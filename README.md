# Windows Motivational Backgrounds

This project will create and automatically update a Windows device's background with motivational quotes, lessons, and more. 

# How to Use

## Initial download

1. Download the code an unzip it anywhere

## Adding quotes

1. [Install Python](https://www.python.org/downloads/) and [add it to PATH](https://phoenixnap.com/kb/add-python-to-path)
2. Locate where the main.py file is
3. Run the following command `python main.py "Insert Quote Here"`

## Automatically updating the background

1. Create an automatic Windows scheduled event [See Article](https://www.windowscentral.com/how-create-automated-task-using-task-scheduler-windows-10)
   - The .exe to be used is the *WMB-1.0.2 Release.exe* located in the **WMB** folder
   - For the "Start In", put the directory that the .exe file is in

## Further customizations
 - You can upload any .ttf file into the **fonts** folder, and update the main.py file to use your new file
 - You can also change the color of the background

# Example

A new examples I have on my personal device are as follows

![Screenshot of my desktop with "root issue"](https://github.com/ye-spencer/Windows-Motivational-Backgrounds/blob/main/md%20files/root%20issue.png)

![Screenshot of my desktop with "smile"](https://github.com/ye-spencer/Windows-Motivational-Backgrounds/blob/main/md%20files/smile.png)

![Screenshot of my desktop with "seek discomfort"](https://github.com/ye-spencer/Windows-Motivational-Backgrounds/blob/main/md%20files/seek%20discomfort.png)

# Process & Challenges

The motivation for this project was to solve an issue that has plagued me for a while. I aim to live by certain ideals and principles; however, I still struggle to implement them in the moment. One barrier has been I simply do not think about these ideals often enough to have them engrained. So I formulated the idea to have these mantras become my PC's background.

Creating the images was straightforward. The script takes an quote from the command line, and uses Python's Imaging Library to put the text in the middle of a black screen, then it saves the image into a folder.

To set the background was marginally more complex. I had to get the current working directory, and cycle through the image folder twice; once to count the number of images and once to select a random one, because files are not indexed in an array. All that was left afterwards to set the background using the windows library.

Automating background changes was the most tricky part. I had to play around with Windows Task Manager to find the correct settings to run a .exe file and set the proper permissions for it, and it was annoying to have to logout and log back in multiple times to test the triggers. Thankfully, it all worked in the end through setting the script to have admin permissions to alter computer settings.

## Interesting Features & Discussion

I had a difficult time deciding on a default look for the backgrounds, put finally settled on white text on a black background. This felt ideal since a black background would help decrease power usage, and increase the contrast between the text and background to instantly attract the eye to the text on login.



