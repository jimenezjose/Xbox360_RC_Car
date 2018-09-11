# Xbox360_RC_Car
How to make an Xbox 360 controlled RC car.
## Materials Needed
- Arduino Mega 2560
- [USB Host Shield](https://www.amazon.com/gp/product/B0777DR3T6/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1)
- [HC-06](https://www.aliexpress.com/item/hc-06-HC-06-RF-Wireless-Bluetooth-Transceiver-Slave-Module-RS232-TTL-to-UART-converter-and/32342784842.html?spm=2114.search0104.3.1.79ce13d2qctt7T&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=158111f5-c4fc-42ac-b751-206c2e3157c1-0&algo_pvid=158111f5-c4fc-42ac-b751-206c2e3157c1&transAbTest=ae803_1&priceBeautifyAB=0)
- [L298N dual H-Bridge](https://www.aliexpress.com/item/Free-Shipping-New-Dual-H-Bridge-DC-Stepper-Motor-Drive-Controller-Board-Module-L298N-MOTOR-DRIVER/32769190826.html?spm=2114.search0104.3.1.5d6f7c3aoKtXZs&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=cf1a614a-d31a-4e1a-860b-7835930ec4b3-0&algo_pvid=cf1a614a-d31a-4e1a-860b-7835930ec4b3&transAbTest=ae803_1&priceBeautifyAB=0)
- [Xbox 360 wireless PC receiver](https://www.amazon.com/gp/product/B00FAS1WDG/ref=oh_aui_detailpage_o01_s01?ie=UTF8&psc=1)

__Material Explanation__:

[USB Host Shield](https://www.amazon.com/gp/product/B0777DR3T6/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1):

[HC-06](https://www.aliexpress.com/item/hc-06-HC-06-RF-Wireless-Bluetooth-Transceiver-Slave-Module-RS232-TTL-to-UART-converter-and/32342784842.html?spm=2114.search0104.3.1.79ce13d2qctt7T&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=158111f5-c4fc-42ac-b751-206c2e3157c1-0&algo_pvid=158111f5-c4fc-42ac-b751-206c2e3157c1&transAbTest=ae803_1&priceBeautifyAB=0): 

        Enables wireless data communication via bluetooth. Powerful accessory to emulate a bluetooth
      terminal and serial data monitor. The advantage of using a bluetooth module, is that it is 
      easily compatible with all industry devices such as a Samsung Galaxy and Andoids and there 
      are is a plethora of arduino applications for such projects open to the public in the Google
      PlayStore. A disadvantage is that IOS devices cannot communicate with the HC-06 bluetooth module
      due to liscensing. Which in my situation was a significant disadvantage because I own an iPhone. 
      The way I worked around this problem is by emulating a bluetooth terminal on my MacBook Pro 
      using its built in terminal. 
        How? Open two seperate terminal windows, enter "cd /dev/" to change into the device directory
      located in root. Then search for your HC-06 Bluetooth device with "ls cu.*". In my case, my 
      HC-06 device file is named "cu.HC-06-DevB". Once your device file is correctly identified 
      use the command "cat (the device file)". For example, in my case I would enter "cat 
      cu.HC-06-DevB". Now this will only display content that is being sent from your bluetooth
      module. To send bytes of data to your HC-06, enter the command, "cat > (the device file)" on 
      the second terminal window you opened. In my case I would enter, "cat > cu.HC-06-DevB". This 
      command redirects keyboard input into the wireless bluetooth module and thats it! For more 
      insight check out my Youtube video I made just for this.
      
[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/YZt1I9wl40M/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLDywz8dIbgiX1RuGBQiZHlcb-N5sg)](https://www.youtube.com/watch?v=YZt1I9wl40M&t=3s)

[L298N dual H-Bridge](https://www.aliexpress.com/item/Free-Shipping-New-Dual-H-Bridge-DC-Stepper-Motor-Drive-Controller-Board-Module-L298N-MOTOR-DRIVER/32769190826.html?spm=2114.search0104.3.1.5d6f7c3aoKtXZs&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=cf1a614a-d31a-4e1a-860b-7835930ec4b3-0&algo_pvid=cf1a614a-d31a-4e1a-860b-7835930ec4b3&transAbTest=ae803_1&priceBeautifyAB=0)
          
      Allows a higher voltage battery to externally power the dc motors (max 46v), safely protecting the 
    arduino from electrical failure due to either supllying an over-voltage to a motor, drawing an 
    excessive amount current due to load, and reverse voltage. The advantages of using an external dual 
    H-Bridge module is the ability of controlling higher voltages and a amperage (max 46v and 2A) comapred 
    to a max 5v and 40mA digitial pin on an arduino at a low cost. The disadvantage, is the 2 volt voltage 
    drop and an increase in project real estate.

[Xbox 360 wireless PC receiver](https://www.amazon.com/gp/product/B00FAS1WDG/ref=oh_aui_detailpage_o01_s01?ie=UTF8&psc=1)
     
        Pertaining an official Microsoft Xbox 360 PC reciever secures the wireless controller connection. 
      The advantages of using an Xbox 360 controller for an RC project is the concept of being able to hack 
      an Xbox controller to intuitively navigate a car just like a car game emulation. A disadvantage to 
      using an Xbox controller, is the low controller reachability of 20ft. But that's fine the Xbox 360 
      controller is really the beuaty of this project. 

__Note__:

        The material needed to make the rc car compatible with an Xbox 360 controller is the USB host sheild 
      and an Xbox 360 wireless receiver. The USB host shield I used, occupied pin 10 on the arduino board as 
      Slave Select, and pin 9 as a serial pathway to program the USB host shield. It may not be for all 
      shields but I found this out myself in this particular model. For this reason I do not attach pins 
      to sockets 9 or 10. Also I believe because pin 10 and 9 were used as SS and Serial transmission 
      respectively, the Arduino Uno did not work with this shield. A solution might be to externally map 
      pins 9 and 10 to appropriate sockets on the Arduino Uno.
      
## [File Diagram](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/images/Xbox360_RC_Car%20Program%20Flow.jpg):
![alt text]( https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/images/Xbox360_RC_Car%20Program%20Flow.jpg "Program flow")

  - [Xbox360_RC_Car.ino](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/Xbox360_RC_Car/Xbox360_RC_Car.ino)
  
  - [Controller.h](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/Xbox360_RC_Car/Controller.h)
  
  - [Controller.ino](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/Xbox360_RC_Car/Controller.ino)
  
  - [BluetoothTerm.h](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/Xbox360_RC_Car/BluetoothTerm.h)
  
  - [BluetoothTerm.ino](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/Xbox360_RC_Car/BluetoothTerm.ino)
  
## [Schematic Overview](https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/images/Schematic.jpg)  
![alt text]( https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/images/Schematic.jpg "Schematic Overview")

## [Images](https://github.com/jimenezjose/Xbox360_RC_Car/tree/master/images):

![alt text]( https://github.com/jimenezjose/Xbox360_RC_Car/blob/master/images/RC_Car_With_Controller.JPG "RC car")

__
