# Lightpack-initiator
Our old internal tool for firmware uploading and testing Lightpacks in an endless, batch mode during production. It is simple cross-platform GUI that uses [Atmel FLIP](http://www.atmel.com/tools/FLIP.aspx) utility as it's main head. 

Initiator perform erase-write-verify process with AT90USB162 MCU and then run test Python script to animate LEDs for visual check and other QA needs.
