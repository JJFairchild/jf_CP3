# Jonas Fairhcild, Pygame Notes

import pygame
import random
import math
from pygame import mixer
# Pygame setup
pygame.init()


screen = pygame.display.set_mode((800,600))
pygame.display.set_caption("Space Invaders")
icon = pygame.image.load("Notes/Pygame Notes/Resources/ufo.png")
pygame.display.set_icon(icon)

bg = pygame.image.load("Notes/Pygame Notes/Resources/background.jpg")
bg = pygame.transform.scale(bg, (800,600))
sfont = pygame.font.Font("freesansbold.ttf", 32)
lfont = pygame.font.Font("freesansbold.ttf", 64)

mixer.music.load("Notes/Pygame Notes/Resources/background.wav")
mixer.music.play(-1)

laser = mixer.Sound("Notes/Pygame Notes/Resources/laser.wav")
explosion = mixer.Sound("Notes/Pygame Notes/Resources/explosion.wav")

class Bullet:
    def __init__(self, x):
        self.x = x + 16
        self.y = 500
        self.speed = -.4
        self.state = "r"
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/bullet.png")
        self.img = pygame.transform.rotate(self.img, 90)

    def show(self):
        if self.state == "f":
            screen.blit(self.img, (self.x, self.y))
        

    def move(self):
        if self.state == "f":
            self.y += self.speed
            if self.y <= -32:
                self.state = "r"


class Player:
    def __init__(self, speed=0):
        self.img = pygame.image.load("Notes/Pygame Notes/Resources/spaceship.png")
        self.x = 368
        self.y = 500
        self.speed = speed
        self.score = 0
        

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
        if math.sqrt((self.x - bullet.x) ** 2 + (self.y - bullet.y) ** 2) < 48 and bullet.state == "f":
            return True
        return False
    
    def lose(self):
        if self.y > 500:
            return True
        return False


player = Player()
enemies = []
for _ in range(6):
    enemies.append(Enemy(
        random.randint(0, 736), 
        random.randint(0, 236)
    ))
bullet = Bullet(player.x)
game_over = False

def restart(enemies):
    # If the player kills all the enemies, this spawns a new wave
    if enemies == []:
        for _ in range(6):
            enemies.append(Enemy(
                random.randint(0, 736), 
                random.randint(0, 236)
            ))
    return enemies

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
                    laser.play()
                    bullet = Bullet(player.x)
                    bullet.state = "f"
        
        if event.type == pygame.KEYUP:
            if event.key in (pygame.K_LEFT, pygame.K_RIGHT):
                player.speed = 0

    for i, enemy in enumerate(enemies):
        if enemy.isHit(bullet):
            explosion.play()
            player.score += 1
            bullet.state = "r"
            bullet.y = 500
            del enemies[i]

    enemies = restart(enemies)

    # Move things
    if not game_over:
        player.move()
        for enemy in enemies:
            enemy.move()
            if enemy.lose():
                enemies = []
                game_over = True
        bullet.move()

    # Display things
    screen.fill((0,0,0))
    screen.blit(bg)
    score = sfont.render(f"Score: {player.score}", True, (255, 255, 255))
    screen.blit(score, (10,10))
    player.show()
    for enemy in enemies:
        enemy.show()
    bullet.show()
    if game_over:
        lose = lfont.render("GAME OVER", True, (255, 255, 255))
        screen.blit(lose, (200, 150))
    
    pygame.display.flip() # Refresh display