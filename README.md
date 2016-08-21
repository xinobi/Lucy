### Lucy is lightweight UI & Input framework for projects created in Unreal Engine 4. 

[Click image below to watch quick video preview]

[![Lucy UI: Log #1](http://i.imgur.com/zCrnxoS.png)](https://www.youtube.com/watch?v=zsqyVt15XkE "Lucy UI: Log #1")

### It's free to use, even commercially.
* Based on UMG, written mostly in blueprints. 
* It allows for compositing UI from fully reusable widgets (I call it composites). Define widget style and logic once, use it hundred times! Or define logic once and set different appearance for every widget instance.
* In clean UMG (without any own scripts) you have to script every element (like button, text or slider) individually. It means lots of copy-pasting scripts responsible for input, localization, styling, setting and restoring state. Everything. Of course many developers close part of those scripts in reusable functions and apply them at every element. My approach is to close entire functionality of element or element group in separate widget file, then simply put this widget in UI panel and fill up parameters. Element added in UMG's Designer tab works out of the box. There's no need to script anything except your custom game logic.
* Appearances of widgets placed in panels refresh automatically after change - which isn't possible in pure UMG.
* And I'm adding a lot of common functions for managing UI panels and input (not only UI related).

### Take a look!
This is entire script for Pause Menu, as simple as it always should be.

![Alt](http://i.imgur.com/Y0VAygC.png "Pause Menu")

You don't need to produce spaghetti blueprint for every UI element. Prepare it quickly by setting params.

![ALT](http://i.imgur.com/2e31OQV.png "Params")

### What's inside?
* Typical UI composites like Text Button, Interaction Hint, Labeled Slider, etc. Every composite automatically updates its default state based on instance values.
* Scripts called UI Manager and Panel take care of creating and switching panels, opening panels in hierarchy, handling input, basic navigation, activating chosen widget in panel, receiving input from active widget. So you don't have to script basic widget actions in your panels. Focus on designing it and scripting custom and advanced functions.
* Samples of Main/Options menus simplifies creating your own menus, i.e. Video Menu allows you to set common graphics options. Just customize it to your needs. Or just download it, don't change a thing and enjoy basic menus working in your cooked build.
* Input Manager provides basic functionalities: setting various inputs for single action, activating interactions, detecting input device and automatically updating displayed icon and key of interaction.
* You don't have to reinvent the wheel when you're starting work on UI. I already did it. Partially ;)

### All the links
* [Wiki: Getting Started](https://github.com/kjustynski/Lucy/wiki/Getting-Started)
* [Trello Board](https://trello.com/b/p4HZ0RuB/lucy)
* [Twitter](https://twitter.com/kjustynski)
* [UE4 forum thread](https://forums.unrealengine.com/showthread.php?120313-FREE-Lucy-lightweight-UI-amp-Input-framework)

### Donate if you like it :)
[![Donate](https://www.paypal.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=LDSUHMU28QRRL)

### Third-party 
* Few blueprint functions from [LE Extended Standard Library](https://www.unrealengine.com/marketplace/low-entry-extended-standard-library).
* Controller icons created by [Xelu](http://opengameart.org/content/free-keyboard-and-controllers-prompts-pack).
* Miscellaneous icons from  [To [icon]](http://www.toicon.com/about) project.
* Chopin's Nocturne performed by Frank Levy. More at [Musopen.org](https://musopen.org/music/245/frederic-chopin/nocturnes-op-9/).

