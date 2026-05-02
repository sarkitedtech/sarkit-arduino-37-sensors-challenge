"""
SARKIT EdTech Project
Title: Arduino Joystick Controlled Snake Game
Description:
A Snake game built using Pygame where movement is controlled via an Arduino joystick.
Arduino sends serial commands (LEFT, RIGHT, UP, DOWN, RESTART).

Author: SARKIT EdTech
"""

import pygame        # For game graphics and window handling
import random        # For random food generation
import serial        # For Arduino serial communication
import time          # For delay handling


# ==============================
# SERIAL CONNECTION SETUP
# ==============================

# Connect to Arduino (Change COM port if required)
ser = serial.Serial('COM9', 9600, timeout=1)

# Allow Arduino time to initialize
time.sleep(2)


# ==============================
# PYGAME INITIALIZATION
# ==============================

pygame.init()

# Window dimensions
width = 600
height = 400

# Create game window
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Arduino Joystick Snake - SARKIT EdTech")

# Font for text display
font = pygame.font.SysFont(None, 35)

# Game settings
snake_block = 10     # Size of snake segment
snake_speed = 12     # Speed of game

# Clock for FPS control
clock = pygame.time.Clock()


# ==============================
# HELPER FUNCTIONS
# ==============================

def draw_score(score):
    """Display score on top-left corner"""
    value = font.render("Score: " + str(score), True, (255, 255, 255))
    screen.blit(value, [10, 10])


def draw_snake(block, snake_list):
    """Draw the snake using rectangles"""
    for segment in snake_list:
        pygame.draw.rect(screen, (0, 255, 0),
                         (segment[0], segment[1], block, block))


def message(msg, color):
    """Display message at center of screen"""
    mesg = font.render(msg, True, color)
    screen.blit(mesg, [width / 6, height / 3])


# ==============================
# MAIN GAME FUNCTION
# ==============================

def game():

    # Initial position of snake (center)
    x = width / 2
    y = height / 2

    # Movement variables
    x_change = 0
    y_change = 0

    # Snake body
    snake_list = []
    length = 1

    # Generate first food position
    foodx = round(random.randrange(0, width - 10) / 10) * 10
    foody = round(random.randrange(0, height - 10) / 10) * 10

    # Score
    score = 0

    # Game states
    game_over = False
    game_close = False


    # ==============================
    # GAME LOOP
    # ==============================

    while not game_over:

        # ==============================
        # GAME OVER SCREEN
        # ==============================
        while game_close:
            screen.fill((0, 0, 0))

            message("Press Joystick Button to Restart", (255, 0, 0))
            draw_score(score)

            pygame.display.update()

            # Listen for restart command from Arduino
            if ser.in_waiting:
                cmd = ser.readline().decode().strip()

                if cmd == "RESTART":
                    game()   # Restart game


        # Handle window close event
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True


        # ==============================
        # ARDUINO INPUT HANDLING
        # ==============================
        if ser.in_waiting:
            direction = ser.readline().decode().strip()

            # Prevent reverse movement
            if direction == "LEFT" and x_change == 0:
                x_change = -snake_block
                y_change = 0

            elif direction == "RIGHT" and x_change == 0:
                x_change = snake_block
                y_change = 0

            elif direction == "UP" and y_change == 0:
                y_change = -snake_block
                x_change = 0

            elif direction == "DOWN" and y_change == 0:
                y_change = snake_block
                x_change = 0


        # ==============================
        # UPDATE SNAKE POSITION
        # ==============================
        x += x_change
        y += y_change


        # Check wall collision
        if x >= width or x < 0 or y >= height or y < 0:
            game_close = True


        # ==============================
        # RENDERING
        # ==============================
        screen.fill((0, 0, 0))

        # Draw food
        pygame.draw.rect(screen, (255, 0, 0),
                         (foodx, foody, snake_block, snake_block))

        # Snake head
        snake_head = [x, y]
        snake_list.append(snake_head)

        # Maintain snake length
        if len(snake_list) > length:
            del snake_list[0]

        # Self collision detection
        for block in snake_list[:-1]:
            if block == snake_head:
                game_close = True

        # Draw snake and score
        draw_snake(snake_block, snake_list)
        draw_score(score)

        pygame.display.update()


        # ==============================
        # FOOD COLLISION
        # ==============================
        if x == foodx and y == foody:

            # Generate new food
            foodx = round(random.randrange(0, width - 10) / 10) * 10
            foody = round(random.randrange(0, height - 10) / 10) * 10

            length += 1
            score += 10


        # Control speed
        clock.tick(snake_speed)


    pygame.quit()


# ==============================
# ENTRY POINT
# ==============================

if __name__ == "__main__":
    game()