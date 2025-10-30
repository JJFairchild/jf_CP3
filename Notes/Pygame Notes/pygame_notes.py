# Jonas Fairhcild, Pygame Notes

import pygame

pygame.init()

screen = pygame.display.set_mode((1200, 720))
pygame.display.set_caption("Pygame Tutorial")

x = 100
y = 200

ufo = pygame.image.load("Notes/Pygame Notes/ufo.png")
ufo_rect = ufo.get_rect(topleft = (512, 512))

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            x -= 5
        if keys[pygame.K_RIGHT]:
            x += 5
        if keys[pygame.K_UP]:
            y -= 5
        if keys[pygame.K_DOWN]:
            y += 5


    screen.fill((0,0,255))
    pygame.draw.rect(screen, (250,0,0), (x, y, 200, 100))
    pygame.draw.circle(screen, (0,0,0), (500, 500), 50)
    screen.blit(ufo, ufo_rect)

    pygame.display.flip()