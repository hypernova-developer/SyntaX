from betterpygame import Engine

def main():
    # Initialize the SyntaX Engine for Python
    app = Engine("SyntaX for Python - Pygame Sample", 1280, 720)

    # Main Application Loop
    while app.is_running():
        # 1. Handle Events
        app.update()

        # 2. Clear Screen with Neon Purple
        app.clear()

        # 3. Refresh Display
        app.render()

if __name__ == "__main__":
    main()
