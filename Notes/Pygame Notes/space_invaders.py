# Jonas Fairhcild, Pygame Notes

import pygame
import random

# Pygame setup
pygame.init()
screen = pygame.display.set_mode((800,600))
pygame.display.set_caption("Space Invaders")
pygame_icon = pygame.image.load("Notes/Pygame Notes/Resources/ufo.png")
pygame.display.set_icon(pygame_icon)

class Player:
    def __init__(self, x, speed=0):
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/spaceship.png")
        self.x = x
        self.y = 500
        self.speed = speed

    def show(self):
        screen.blit(self.img, (self.x, self.y))

    def move(self):
        self.x += self.speed
        if self.x <= 0:
            self.x = 0
        elif self.x >= 736:
            self.x = 736

class Enemy:
    def __init__(self, x, y, speed):
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/alien.png")
        self.x = x
        self.y = y
        self.speed = speed

    def show(self):
        screen.blit(self.img, (self.x, self.y))

player = Player(368)

running = True
while running:

    # Events
    for event in pygame.event.get():
        keys = pygame.key.get_pressed()

        if event.type == pygame.QUIT:
            running = False
        
        if event.type == pygame.KEYDOWN:
            if keys[pygame.K_LEFT]:
                player.speed = -.1
            if keys[pygame.K_RIGHT]:
                player.speed = .1   
        
        if event.type == pygame.KEYUP:
            if event.key in (pygame.K_LEFT, pygame.K_RIGHT):
                player.speed = 0
            
    player.move()

    # Display things
    screen.fill((0,0,0))
    player.show()

    pygame.display.flip() # Refresh display