Escáner de libros automático.
============================
######Proyecto de Mario Navarro y Pablo Otón para la asignatura Automatización Industrial de 3º del Grado en Ingeniería Electrónica industrial y automática de la UPCT.
####Se trata de un escáner de libros totalmente automático. Pasador de páginas basado en la técnica industrial de vacío y ventosa.
####En este primer prototipo, debido a la asignatura a la que va vinculado, nos vemos obligados a utilizar módulos neumáticos industriales y depender de un compresor de aire.
####En futuros prototipos usaremos un sistema que permita una solución más portable y silenciosa.

![1](http://i.gyazo.com/fb20c3760d65ccf924531efab7c1a3b4.png)
![2](http://i.gyazo.com/1a5dec6576b23358d52b24a8013a377f.png)
![3](http://i.gyazo.com/74e7db85763c5f15cc9b6696c042dec1.png)

#1.-Código Arduino
######En la carpeta 'Codigo_Arduino' podemos descargar el código de este primer prototipo.
##1.1-Librerías Usadas
######Para hacer funcionar el código hay que incluir las dos librerías siguientes:
###1.1.1.-Librería FSM
######La librería 'FSM' nos permite implementar con Arduino la secuencia de funcionamiento en formato de máquina de estados.
######Creada por Igor Real.
######Descargar en: https://github.com/IgorReal/SECUduino/tree/master/FSM%20Library
###1.1.2.-Librería Unipolar
######La librería 'Unipolar' nos permite controlar con una única línea el motor paso a paso unipolar 28BYJ48.
######Descargar en: https://github.com/PabloOton/Libreria-24BYJ48

#2.-Hardware
##2.1.-Electrónica
![4](http://i.gyazo.com/ca455526cdab26c6c30360fc9e291077.png)
####2.1.1.-Finales de carrera superior e inferior: 
######El final de carrera inferior lo hemos sustituido por un presostato (ver apartado 2.2). 
######El final de carrera superior realmente no es necesario, al tratarse de un motor paso a paso; Pero en este primer prototipo nos decantamos por poner el final de carrera superior porque a la hora de hacer los numerosos ajustes es más cómodo cambiar la posición del final de carrera que reajustar los pasos del motor.

####2.1.2.-Circuito integrado ULN2003
######Usamos el array de 7 transistores darlington ULN2003 para las 4 fases del motor paso a paso y para excitar la bobina del relé que controla la electroválvula.

![6](http://i.gyazo.com/349e4aad2ffad7543b9b2e6c0176a0b0.png)

####2.1.3.-Módulos industriales
######Dado que usamos módulos industriales para la parte de neumática (están detallados en el apartado siguiente 2.2) nos vemos obligados a trabajar en una zona con 24v y adaptar estas entradas y salidas a 5v, que es lo que admite Arduino. 
#####Tenemos una salida a 24v; la electroválvula FESTO OVEM: 
######Pasamos de 5v a 24v con un relé excitado con un transistor Darlington del integrado ULN2003 como ya hemos visto.
#####Tenemos una entrada a 24v; el presostato FESTO PEV-W: 
######Pasamos de 24v a 5v con un divisor resistivo. Con una resistencia de 4k a +24V conectada a una resistencia de 1k que a su vez va a GND. Así, entre el punto de unión de ambas resistencias y GND tenemos una caída de 4,8v.

##2.2.-Neumática
######El diagrama neumático simplificado es el siguiente:
![5](http://i.gyazo.com/766c2b8b3302a408c1d8a34390902d5c.png)

######Usamos un compresor de 8bar. y 25L regulado a 2bar. en su salida.
######Para generar el vacío (presión negativa), a partir de la presión positiva que nos proporciona el compresor usamos una válvula FESTO OVEM, que incorpora el venturi y la electroválvula 2/2.
######Para detectar cuando la ventosa llega hasta abajo y succiona la página del libro, usamos un presostato FESTO PEV-W, configurado como NC, que nos devuelve un nivel bajo cuando detecta vacío. 


#3.-Modificaciones pendientes, mejoras
######No depender del sistema neumático.
######Cambiar el motor de la cremallera por uno más rápido. 
######Display con encoder para configuración e introducir nº de páginas a escanear.



