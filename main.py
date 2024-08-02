# main.py
# Author: Spencer Ye
# Last Modified: August 2nd, 2024
# Version: 0.3.0

#from PIL import Image, ImageDraw, ImageFont
import pathlib
import sys
print(sys.executable)
exit(0)

# Load the image
curr_directory = str(pathlib.Path(__file__).parent.resolve())


image = Image.open(curr_directory + "\\background_images\\background.jpg")

# Create a drawing context
draw = ImageDraw.Draw(image)

# Define the text properties
font = ImageFont.truetype(curr_directory + "\\fonts\\OldNewspaperTypes.ttf", 36)
text = "Hello, World!"
position = (50, 50)

# Add text to the image
draw.text(position, text, font=font)

# Save or display the modified image
image.save(str(curr_directory) + "\\outs.jpg")