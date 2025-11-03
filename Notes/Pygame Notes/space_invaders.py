# Jonas Fairhcild, Pygame Notes

import pygame
import random
import math

# Pygame setup
pygame.init()
screen = pygame.display.set_mode((800,600))
pygame.display.set_caption("Space Invaders")
pygame_icon = pygame.image.load("Notes/Pygame Notes/Resources/ufo.png")
pygame.display.set_icon(pygame_icon)

class Bullet:
    def __init__(self, x):
        self.x = x + 16
        self.y = 500
        self.speed = -.2
        self.state = "r"
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/bullet.png")
        self.rimg = pygame.transform.rotate(self.img, 90)

    def show(self):
        screen.blit(self.rimg, (self.x, self.y))
        

    def move(self):
        self.y += self.speed
        if self.y <= -32:
            self.state = "r"


class Player:
    def __init__(self, speed=0):
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/spaceship.png")
        self.x = 368
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
    def __init__(self, x, y):
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/alien.png")
        self.x = x
        self.y = y
        self.speedx = (.3 if random.randint(0, 1) == 1 else -.3)
        self.speedy = 20

    def show(self):
        screen.blit(self.img, (self.x, self.y))

    def move(self):
        self.x += self.speedx
        if self.x <= 0:
            self.speedx = .3
            self.y += self.speedy
        if self.x >= 736:
            self.speedx = -.3
            self.y += self.speedy

    def isHit(self, bullet):
        if math.sqrt((self.x - bullet.x) ^ 2 + (self.y - bullet.y) ^ 2) < 27:
            return True
        return False

player = Player()
enemy = Enemy(
    random.randint(0, 736), 
    random.randint(0, 236)
)
bullet = Bullet(player.x)

running = True
while running:

    # Events
    for event in pygame.event.get():
        keys = pygame.key.get_pressed()

        # Quit game
        if event.type == pygame.QUIT:
            running = False
        
        # Keyboard handling
        if event.type == pygame.KEYDOWN:
            if keys[pygame.K_LEFT]:
                player.speed = -.2
            if keys[pygame.K_RIGHT]:
                player.speed = .2
            if keys[pygame.K_UP]:
                if bullet.state == "r":
                    bullet = Bullet(player.x)
                    bullet.state = "f"
        
        if event.type == pygame.KEYUP:
            if event.key in (pygame.K_LEFT, pygame.K_RIGHT):
                player.speed = 0
            
    player.move()
    enemy.move()

    # Display things
    screen.fill((0,0,0))
    player.show()
    if bullet.state == "f":
        bullet.move()
        bullet.show()
    enemy.show()

    pygame.display.flip() # Refresh display