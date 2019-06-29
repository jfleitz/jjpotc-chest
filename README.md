# JJPOTC Treasure Chest Mod
## Background
I have to admit, the Pirates of the Caribbean by Jersey Jack Pinball (JJPOTC for short), is my favorite game in my collection. It plays fast, has a lot of shots and modes, plenty of eye-candy, and is so much fun to play with the family to boot.

### Why the mod
So why this mod? When this game was first showed off at Chicago Pinball Expo 2017, there were two additional features in the game that didn't make it to production.

The first was the 3 disc spinner, which IMO, was totally fine to remove (I like the screen version better as it is more dramatic than trying to squint and see what the map is pointing to lol).

The second was the treasure chest automatically opening and closing. The reason it was removed was due to ball rejects, and not always locking the ball in the chest. I am pretty sure this was really due to it being mechanically coupled to the fork ramp.

## Bill of Materialshttps://www.amazon.com/gp/product/B01KYBXQEQ/ref=ppx_od_dt_b_asin_title_s01?ie=UTF8&th=1
The [materials.md](materials.md) file has the BOM to make this

## Hardware
The requirement for any mod to me, is the ability to remove it without any damage to the game. The hardware of this mod includes:
1. a servo (metal geared for longevity)
2. Arduino nano for controlling the servo
3. 3D printed bracket used for mounting the servo and the Arduino
4. Steel plate that replaces the existing metal bracket holding the chest lid open
5. Metal Hinge
6. Pushrod / linkage

### Servo
A standard 5v servo is used to drive a pushrod linkage that opens and closes the actual chest.

### Arduino Nano
An Arduino Nano is used to drive the servo. They are cheap and can drive 1 servo without an external driver.

For testing, the arduino's USB port was used for power, with a USB adapter plugged into the service port.
For permanent installation, an ATX Y-Adapter is used, with the 5volt rail (Red wire) being wired into the 5V pin.

### Microswitch
This is the actuator that is triggered from the fork mech (similar to the existing switch on the fork mech, but located on the bottom).

### Bracket
The 3D printed bracket can be found in the root folder called `chest-bracket.stl`, but it can also be found on thingiverse [here](https://www.thingiverse.com/thing:3719361)

This is used to mount the servo, arduino, and switch.

## Software
Very simple sketch that is based on both the debounce example and the servo example included in the Arduino libraries.

## Example in action
You can see an example of all of this in action [here](https://youtu.be/9_Q9q7z8Kys)

## TODO
- [X] Modify bracket to include switch mount
- [X] Create metal bracket for the chest
- [ ] Add Bill of Materials
- [ ] Add links to ordering parts
- [ ] Add pictures
