//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// paddle properties
#define PADDLEWIDTH 60
#define PADDLEHEIGHT 10

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // initial ball velocity
    double x_velocity = 2.0;
    double y_velocity = 2.0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
    
        // move the paddle
    
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows horizontal cursor movement
                double x = getX(event) - getWidth(paddle) / 2;
                if ( x < 0)
                {
                    x = 0;
                }
                if ( x > WIDTH - getWidth(paddle) )
                {
                    x = WIDTH - getWidth(paddle);
                }
                   
                setLocation(paddle, x, HEIGHT * 9/10);
            }
        }
        
        // bounce the ball
        
        // move circle
        move(ball, x_velocity, y_velocity);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            x_velocity = -x_velocity;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            x_velocity = -x_velocity;
        }
        
        // bounce off top edge of window
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            y_velocity = -y_velocity;
        }

        // bounce off bottom edge of window
        else if (getY(ball) <= 0)
        {
            y_velocity = -y_velocity;
        }
        
        // linger before moving again
        pause(10);
    }
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // constants for individual brick
    int brick_gap = 4;
    int brick_width = WIDTH/10 - brick_gap;
    int brick_height = 12;
    int x = 2;
    int y = HEIGHT * 1/10;
    string colors[5];
    colors[0] = "RED";
    colors[1] = "ORANGE";
    colors[2] = "YELLOW";
    colors[3] = "GREEN";
    colors[4] = "CYAN";
    
    for (int row = 0; row < ROWS; row++)
    {
        
        for (int col = 0; col < COLS; col++)
        {
            // create brick
           GRect brick = newGRect(x, y, brick_width, brick_height);
            setFilled(brick, true);
            setColor(brick, colors[row]);     
            add(window, brick);
            x = x + brick_width + brick_gap;
        }
        
        y = y + brick_height + brick_gap;
        x = 2;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2, HEIGHT/2, RADIUS*2, RADIUS*2);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    int x = WIDTH/2 - PADDLEWIDTH/2;
    int y = HEIGHT * 9/10;
    GRect paddle = newGRect(x,y,PADDLEWIDTH, PADDLEHEIGHT);
    
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
