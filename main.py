# main.py
# Author: Spencer Ye
# Last Modified: August 2nd, 2024
# Version: 1.0.0

from PIL import Image, ImageDraw, ImageFont
import pathlib
import pyautogui
import sys

# BEGIN CONSTANTS

BACKGROUND_COLOR = (210, 216, 216)

# END CONSTANTS


def generate_image(text : str):
# Load the current directory
    curr_directory = str(pathlib.Path(__file__).parent.resolve())

    # Get the current device's screen resolutions
    W, H = pyautogui.size()

    # Create background image
    image = Image.new(mode = "RGB", size = (W, H), color = BACKGROUND_COLOR)

    # Create a drawing context
    draw = ImageDraw.Draw(image)

    # Define the font
    font = ImageFont.truetype(curr_directory + "\\fonts\\OldNewspaperTypes.ttf", 36)

    # Get the dimensions of the text so we can center it
    _, _, w, h = draw.textbbox((0, 0), text=text, font=font)

    # Add text to the image
    draw.text(((W - w)/2, (H - h)/2.25), text, font=font, fill="black")

    # Save the image in our directory
    image.save(curr_directory + "\\WMB\\images\\" + text + ".jpg")

def main():
    # Ensure we have enough arguments
    if (len(sys.argv) != 2):
        print("Usage: python main.py \"Quote/Tidbit/Etc.\"")
        exit(-1)
    
    # Generate the image and save it in the proper folder
    generate_image(sys.argv[1])

if __name__ == "__main__":
    main()