Esc�ner de libros autom�tico.
============================
######Proyecto de Mario Navarro y Pablo Ot�n para la asignatura Automatizaci�n Industrial de 3� del Grado en Ingenier�a Electr�nica industrial y autom�tica de la UPCT.
####Se trata de un esc�ner de libros totalmente autom�tico. Pasador de p�ginas basado en la t�cnica industrial de vac�o y ventosa.
####En este primer prototipo, debido a la asignatura a la que va vinculado, nos vemos obligados a utilizar m�dulos neum�ticos industriales y depender de un compresor de aire.
####En futuros prototipos usaremos un sistema que permita una soluci�n m�s portable y silenciosa.

![1](http://i.gyazo.com/fb20c3760d65ccf924531efab7c1a3b4.png)
![2](http://i.gyazo.com/1a5dec6576b23358d52b24a8013a377f.png)
![3](http://i.gyazo.com/74e7db85763c5f15cc9b6696c042dec1.png)

#1.-C�digo Arduino
######En la carpeta 'Codigo_Arduino' podemos descargar el c�digo de este primer prototipo.
##1.1-Librer�as Usadas
######Para hacer funcionar el c�digo hay que incluir las dos librer�as siguientes:
###1.1.1.-Librer�a FSM
######La librer�a 'FSM' nos permite implementar con Arduino la secuencia de funcionamiento en formato de m�quina de estados.
######Creada por Igor Real.
######Descargar en: https://github.com/IgorReal/SECUduino/tree/master/FSM%20Library
###1.1.2.-Librer�a Unipolar
######La librer�a 'Unipolar' nos permite controlar con una �nica l�nea el motor paso a paso unipolar 28BYJ48.
######Descargar en: https://github.com/PabloOton/Libreria-24BYJ48

#2.-Hardware
##2.1.-Electr�nica
![4](http://i.gyazo.com/ca455526cdab26c6c30360fc9e291077.png)
####2.1.1.-Finales de carrera superior e inferior: 
######El final de carrera inferior lo hemos sustituido por un presostato (ver apartado 2.2). 
######El final de carrera superior realmente no es necesario, al tratarse de un motor paso a paso; Pero en este primer prototipo nos decantamos por poner el final de carrera superior porque a la hora de hacer los numerosos ajustes es m�s c�modo cambiar la posici�n del final de carrera que reajustar los pasos del motor.

####2.1.2.-Circuito integrado ULN2003
######Usamos el array de 7 transistores darlington ULN2003 para las 4 fases del motor paso a paso y para excitar la bobina del rel� que controla la electrov�lvula.

![6](http://i.gyazo.com/349e4aad2ffad7543b9b2e6c0176a0b0.png)

####2.1.3.-M�dulos industriales
######Dado que usamos m�dulos industriales para la parte de neum�tica (est�n detallados en el apartado siguiente 2.2) nos vemos obligados a trabajar en una zona con 24v y adaptar estas entradas y salidas a 5v, que es lo que admite Arduino. 
#####Tenemos una salida a 24v; la electrov�lvula FESTO OVEM: 
######Pasamos de 5v a 24v con un rel� excitado con un transistor Darlington del integrado ULN2003 como ya hemos visto.
#####Tenemos una entrada a 24v; el presostato FESTO PEV-W: 
######Pasamos de 24v a 5v con un divisor resistivo. Con una resistencia de 4k a +24V conectada a una resistencia de 1k que a su vez va a GND. As�, entre el punto de uni�n de ambas resistencias y GND tenemos una ca�da de 4,8v.

##2.2.-Neum�tica
######El diagrama neum�tico simplificado es el siguiente:
![5](http://i.gyazo.com/766c2b8b3302a408c1d8a34390902d5c.png)

######Usamos un compresor de 8bar. y 25L regulado a 2bar. en su salida.
######Para generar el vac�o (presi�n negativa), a partir de la presi�n positiva que nos proporciona el compresor usamos una v�lvula FESTO OVEM, que incorpora el venturi y la electrov�lvula 2/2.
######Para detectar cuando la ventosa llega hasta abajo y succiona la p�gina del libro, usamos un presostato FESTO PEV-W, configurado como NC, que nos devuelve un nivel bajo cuando detecta vac�o. 


#3.-Modificaciones pendientes, mejoras
######No depender del sistema neum�tico.
######Cambiar el motor de la cremallera por uno m�s r�pido. 
######Display con encoder para configuraci�n e introducir n� de p�ginas a escanear.



