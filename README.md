# Arduino-Project-IOT-cat-dispenser
En Français:

Pour ce projet j'ai utilisé un Arduino UNO qui intégré un module WiFi ESP8266 + R3 ATmega328P.
Le code donné a été utilisé sur Arduino IDE.

Le but du projet était simplement de mettre en place un distributeur à croquettes pour tout type d'animal domestique. 
Pour ma part c'est un projet destiné à mon chat.

Dans mon cas comme dit plutot j'ai utiliser un carte qui comprenais un arduino UNO et un ESP8266 sur une même carte. 
Il est alors important de dissocier les 2 cartes et de comprendre le rôle de chacun.
En effet tous le programme portant sur les LEDS/boutons/servo/... est utilisé par la partie de l'arduino UNO.
Est pour ce qui est de la connexion sur le réseau c'est par le module ESP8266 que cela passe.


Maintenant que nous avons bien compris que notre carte est composé de 2 modules, on va voir rapidment comment cela fonctionne.

Pour upload le code/sketch sur la partie UNO il faut choisir la carte "Arduino Uno" dans les outils de l'application Arduino IDE.
Ensuite sur la carte il faut mettre sur la position "ON" les bouton 3 et 4.
Après c'est un télévesrsement de code classique.

Pour upload le code/sketch sur le module ESP8266, il faut dans un premier temps installer l'extension "esp8266" dans la gestion des cartes. Ensuite il faut choisir la carte "Generic ESP8266 Module" dans les outils. Avant de procéder au téléversement il est important de repasser à "OFF" les bouton 3 et 4 de la carte et passer à "ON" les boutons 5/6 et 7. Ensuite on peut téléverser.

Vien ensuite une petite manipulation. Il faut repasser le bouton 7 à "OFF" et procéder à un reset de la carte manuellement. Cette manipulation permet à la carte de connecter la communication entre l'ESP8266 et la carte arduino UNO.

Finalement repasser tous les boutons à "OFF", et repasser les boutons 1 et 2 à "ON". Ceci permet à la carte Arduino UNO et l'ESP8266 de communiquer ensemble via le port série et d'effectuer les tâches demandées. Allumer une led... pour l'arduino UNO et s'occuper de la partie WIFI pour l'ESP8266.

In English:

For this project I used an Arduino UNO which integrated an ESP8266 + R3 ATmega328P WiFi module.
The given code was used on Arduino IDE.

The goal of the project was simply to set up a kibble dispenser for any type of pet.
For me, it's a project for my cat.

In my case, as said earlier, I used a card that included an Arduino UNO and an ESP8266 on the same card.
It is therefore important to dissociate the 2 cards and to understand the role of each.
Indeed all the program relating to the LEDS/buttons/servo/... is used by the part of the arduino UNO.
As for the connection to the network, it is through the ESP8266 module that it goes through.


Now that we have understood that our card is made up of 2 modules, we will quickly see how it works.

To upload the code/sketch on the UNO part, you must choose the "Arduino Uno" board in the tools of the Arduino IDE application.
Then on the card it is necessary to put on the position "ON" the buttons 3 and 4.
After that it's a classic code upload.

To upload the code/sketch on the ESP8266 module, you must first install the "esp8266" extension in the card management. Then you have to choose the "Generic ESP8266 Module" card in the tools. Before proceeding with the upload it is important to return to "OFF" buttons 3 and 4 of the card and switch to "ON" buttons 5/6 and 7. Then you can upload.

Then comes a little manipulation. Switch button 7 to "OFF" and reset the card manually. This manipulation allows the board to connect the communication between the ESP8266 and the arduino UNO board.

Finally return all the buttons to "OFF", and return buttons 1 and 2 to "ON". This allows the Arduino UNO board and the ESP8266 to communicate together with the serial port and perform the requested tasks. Turn on a led... for the arduino UNO and take care of the WIFI part for the ESP8266.
