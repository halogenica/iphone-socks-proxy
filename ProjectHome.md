Source for an iPhone App that is a SOCKS Proxy. It allows you to connect your laptop to the Internet through the iPhone's
3G/Edge connection (tethering) without having to jailbreak your iPhone.
If you want to install the application on your iPhone you will have to build and install
the App from the the supplied code. The code is completely legitimate and does not use any undocumented APIs and NO JAIL BREAK is required. But Apple will not approve such an App on its store so you will have to build it yourself:
  * Pay Apple for iPhone development program
  * get a development certificat from Apple's developers portal
  * configure your iPhone for development with Xcode (SDK 4)
  * download the entire [source code](http://code.google.com/p/iphone-socks-proxy/source/checkout) to a Mac
  * double click SOCKS.xcodeproj
  * in the left panel select Targers and then select SOCKS
  * press the "i" Info button on the top
  * select Properties tab
  * In the Identifier field change "symfi" to your company name as it was used in the certificate
  * connect an iPhone using a cable
  * click Build and Debug


In order to use the SOCKS Proxy App for tethering you need to
follow few steps:
  * On your laptop start an ad-hoc Wi-Fi network. On Mac this is done by:
    * System Preferences->Network
    * select AirPort
    * click on Network Name and select Create Network
    * in Name enter "mywifi", press OK, press Apply
  * Connect you iPhone to the add-hoc wifi network:
    * Settings->Wi-Fi
    * select "mywifi"
  * Run this SOCKS App on your iPhone
    * In the SOCS Proxy tab press Start
      * take note of the address and port that appear on the screen.
        * if you get the message "no Wifi" then you are not yet connected to the ad-hoc network. Wait a minute and try again.
      * put your iPhone face down on the table in order to save battery
  * configure your laptop application to use your SOCKS (with the above address and port). Some examples:
    * Safari on Mac (Firefox needs a different configuration):
      * System Preferences->Network->Advanced...
      * select Proxies
      * check SOCKS proxy
      * in the SOCKS Proxy Server field enter the address and port that appear on your iPhone screen
      * press OK
      * press Apply
    * Firfox on Mac
      * Firefox->Preferences...->Advanced->Network->Settings...
      * Select "Manual proxy configuation:"
      * enter IP and port of your iPhone in the SOCKS Host: and Port:
      * OK
    * Unix (Mac) shell commands can be made to use socks (socksify) using the [tsocks](http://tsocks.darwinports.com/) command (check the man page) (see [also](http://www.proxifier.com/)).
      * tsocks is configured using the file /opt/local/etc/tsocks.conf for example, if the proxy is on 169.254.213.179:20000 then the file should look like:
```
local = 127.0.0.1/255.255.255.255
local = 169.254.0.0/255.255.0.0
server = 169.254.213.179
server_port = 20000
server_type = 5
```
    * When finished remember to disable the usage of SOCKS in your laptop application:
      * Safari Mac: uncheck the above SOCKS proxy and press OK and Apply to restore regular connectivity
On iOS device with background capability (iPhone 3GS with iOS 4 or iPhone 4) you can leave the app and do something else (like pulling mail on your iPhone, playing on your iPod app) as long as you return back fast enough (in about 10min) to the SOCKS app.