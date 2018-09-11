# Xbox360_RC_Car
How to make an Xbox 360 controlled RC car.
## Materials Needed
- Arduino Mega 2560
- [USB Host Shield](https://www.amazon.com/gp/product/B0777DR3T6/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1)
- [HC-06](https://www.aliexpress.com/item/hc-06-HC-06-RF-Wireless-Bluetooth-Transceiver-Slave-Module-RS232-TTL-to-UART-converter-and/32342784842.html?spm=2114.search0104.3.1.79ce13d2qctt7T&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=158111f5-c4fc-42ac-b751-206c2e3157c1-0&algo_pvid=158111f5-c4fc-42ac-b751-206c2e3157c1&transAbTest=ae803_1&priceBeautifyAB=0)
- [L298N dual H-Bridge](https://www.aliexpress.com/item/Free-Shipping-New-Dual-H-Bridge-DC-Stepper-Motor-Drive-Controller-Board-Module-L298N-MOTOR-DRIVER/32769190826.html?spm=2114.search0104.3.1.5d6f7c3aoKtXZs&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=cf1a614a-d31a-4e1a-860b-7835930ec4b3-0&algo_pvid=cf1a614a-d31a-4e1a-860b-7835930ec4b3&transAbTest=ae803_1&priceBeautifyAB=0)
- [Xbox 360 wireless PC receiver](https://www.amazon.com/gp/product/B00FAS1WDG/ref=oh_aui_detailpage_o01_s01?ie=UTF8&psc=1)

### Material Explanation
[USB Host Shield](https://www.amazon.com/gp/product/B0777DR3T6/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1):

[HC-06](https://www.aliexpress.com/item/hc-06-HC-06-RF-Wireless-Bluetooth-Transceiver-Slave-Module-RS232-TTL-to-UART-converter-and/32342784842.html?spm=2114.search0104.3.1.79ce13d2qctt7T&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=158111f5-c4fc-42ac-b751-206c2e3157c1-0&algo_pvid=158111f5-c4fc-42ac-b751-206c2e3157c1&transAbTest=ae803_1&priceBeautifyAB=0): Enables wireless data communication via bluetooth. Powerful accessory to emulate a bluetooth terminal and serial data monitor.

[L298N dual H-Bridge](https://www.aliexpress.com/item/Free-Shipping-New-Dual-H-Bridge-DC-Stepper-Motor-Drive-Controller-Board-Module-L298N-MOTOR-DRIVER/32769190826.html?spm=2114.search0104.3.1.5d6f7c3aoKtXZs&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10130_10068_10324_10547_10342_10325_10546_10343_10340_10548_10341_10545_10696_10084_10083_10618_10307_10869_10868_10059_100031_10103_10624_10623_10622_10621_10620,searchweb201603_51,ppcSwitch_4&algo_expid=cf1a614a-d31a-4e1a-860b-7835930ec4b3-0&algo_pvid=cf1a614a-d31a-4e1a-860b-7835930ec4b3&transAbTest=ae803_1&priceBeautifyAB=0)

[Xbox 360 wireless PC receiver](https://www.amazon.com/gp/product/B00FAS1WDG/ref=oh_aui_detailpage_o01_s01?ie=UTF8&psc=1)

__Note__:

        The material needed to make the rc car compatible with an Xbox 360 controller is the USB host sheild 
      and an Xbox 360 wireless receiver. The USB host shield I used, occupied pin 10 on the arduino board as 
      Slave Select, and pin 9 as a serial pathway to program the USB host shield. It may not be for all 
      shields but I found this out myself. For this reason I do not attach pins to sockets 9 or 10. Also
      I believe because pin 10 and 9 were used as SS and Serial transmission respectively, the Arduino Uno 
      did not work with this shield. A solution might be to externally map pins 9 and 10 to appropriate 
      sockets on the Arduino Uno.
      
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
