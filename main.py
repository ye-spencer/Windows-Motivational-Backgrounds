# main.py
# Author: Spencer Ye
# Last Modified: August 2nd, 2024
# Version: 0.3.0

from PIL import Image, ImageDraw, ImageFont
import pathlib
import pyautogui


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
    image.save(str(curr_directory) + "\\WMB\\images\\outst.jpg")

def main():
    # TODO: take in text as an argument
    text = "Hello, World!"
    generate_image(text)

if __name__ == "__main__":
    main()