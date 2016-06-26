# reelbot
DIY hacked together FPV remote-controlled car


## Part list
- Raspberry Pi 3
- SD card
- Arduino Nano
- 4x continuous rotation hacked servos
- 2x H-Bridges
- ... list is not complete


## Setup
- Write the latest rasbian os to the SD card (jessie)
- Connect it. Make sure your usb power supply have enough amps (~2.5A)
- Expand the file system. Menu -> Preferences -> Raspberry Pi Configuration. Click Expand Filesystem button. Ok and then save.
- Select keyboard and language settings.  Menu -> Preferences -> Mouse and Keyboard settings. Select keyboard tab and then Keyboard layout. Make your choice.
- Change password for the pi user (run the `passwd` command in the console)
- Connect to a wifi
- Upgrade stuff. Run `sudo apt-get update` and `sudo apt-get upgrade`. Press Y if needed
- Install stuff: `sudo apt-get install vim screen picocom libftdi1 fail2ban`
- Run `ifconfig` and note the mac address (HWaddr) as it can be nice to have for later to find the pi on a network. Example on how to find the ip of your pi (change the ip and mac): `sudo nmap -sP 192.168.1.0/24 | awk '/^Nmap/{ip=$NF}/00:0F:54:10:AA:AA/{print ip}'`
- Run `pip install -U platformio`
- Get the code `git clone git@github.com:hackheim/reelbot.git`
- Install serial startup script by running `sudo systemctl enable /home/pi/reelbot/reelbot.service`. To start and stop, run `sudo systemctl start|stop reelbot.service`. To connect screen, use `screen -r reelbot`.
- Connect arduino, enter reelbot folder, and run `platformio run --target upload`. Enter Y if asked about platform install
