# Space invaders

exactly what it says


# ChangeLog

31/07/2024 
Fixed a bug which caused textures to not display at all, display wrong, or display like something out of my nightmares. Issue was that everytime an invader would be created, the png and texture would need to be loaded and then unloaded from memory. Adding a static array to hold all invader sprites as part of the invader class fixed this issue. 
