import pygame
import sys

class Engine:
    """
    SyntaX for Python - Pygame Wrapper
    Provides a clean interface for graphical applications.
    """
    
    def __init__(self, title="SyntaX Engine v2.0", width=1280, height=720):
        pygame.init()
        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption(title)
        self.clock = pygame.time.Clock()
        self.running = True
        
        # Official SyntaX Neon Purple (#BC13FE)
        self.brand_color = (188, 19, 254)

    def update(self):
        """Processes event queue to handle window closing."""
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False

    def clear(self, color=None):
        """Clears the screen. Defaults to SyntaX Purple."""
        target_color = color if color else self.brand_color
        self.screen.fill(target_color)

    def render(self, fps=60):
        """Updates the display and caps the framerate."""
        pygame.display.flip()
        self.clock.tick(fps)

    def is_running(self):
        """Checks if the main loop should continue."""
        return self.running

    def __del__(self):
        """Cleanup resources on destruction."""
        pygame.quit()
