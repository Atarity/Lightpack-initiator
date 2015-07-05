# Lightpack-initiator
Our old internal tool for firmware uploading and testing Lightpacks in an endless, batch mode during production. It is simple cross-platform GUI that uses [Atmel FLIP](http://www.atmel.com/tools/FLIP.aspx) utility as it's main head. 

Initiator perform _erase&rarr;write&rarr;verify_ process with AT90USB162 MCU and then run test Python script to animate LEDs for visual check and other QA needs.

<img src="https://lh3.googleusercontent.com/-AvJJJ5PEMOQ/VZlfd9koXuI/AAAAAAAA7zA/mDQzx2pkJ-k/w550-no/Screenshot_15.png" />
