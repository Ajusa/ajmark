![alt text](https://github.com/ajusa/ajmark/raw/master/ajmark.png "ajmark example")

## What is this?

ajmark is a demo application intended to show how ajl can be used to create GUIs. It uses webview, an excellent C library, to render out the interface. It is also fully cross platform 
Linux, Mac, Windows). 

ajmark supports creating and editing files, and it has a live updating preview mode.

## Download
Clone the repository. The `ajmark.exe` file is the binary for Windows. Other operating systems should follow how to build ajl files from [here](www.github.com/ajusa/ajl).

## Why not Electron?
Many reasons. Mostly, I wanted to use my language, but also resource consumption. Due to the lightweight nature of webview, ajmark is currently consuming ~17mb of ram on my machine, and
has a binary that is 284kb large(\*). A similar application using Electron, consumes over *200mb* of ram, and is over **50mb**. 

*Adding the size of the HTML/CSS/JS code makes this number go up slightly, but it is still under 400kb.

Keep in mind, both use web technologies and are fully cross platform. They are very comparable. Using Electron for simple web apps should be avoided where possible. 