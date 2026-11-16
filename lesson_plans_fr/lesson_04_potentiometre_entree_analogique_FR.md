# Leçon 4 : Potentiomètre et entrée analogique

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçon 3 (Boutons). Les élèves doivent avoir un circuit avec bouton fonctionnel.

## Aperçu

À la dernière leçon, le bouton nous donnait deux options : enfoncé ou non. Dans cette leçon, on obtient un nombre n’importe où entre 0 et 1023, selon jusqu’où on tourne un bouton rotatif. Les élèves s’en servent pour contrôler la luminosité d’une DEL.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment fonctionne un potentiomètre et à quoi servent ses trois broches
- La différence entre une entrée analogique et une entrée numérique
- Comment utiliser analogRead pour obtenir une valeur du potentiomètre
- Comment utiliser analogWrite pour contrôler la luminosité d’une DEL
- Comment utiliser le moniteur série pour voir ce que l’Arduino lit réellement

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 1 DEL (n’importe quelle couleur)
- 1 résistance de 220 Ω
- 1 potentiomètre (10 kΩ)
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad

### La physique (gardons ça simple)

Un potentiomètre est une résistance variable. On tourne le bouton, la résistance change, et la tension qui arrive à la broche du milieu change aussi.

L’Arduino lit cette tension et la convertit en un nombre de 0 à 1023.

Pour les DEL, analogWrite va seulement de 0 à 255. On divise donc par 4 pour entrer dans cette plage.

## Avant la leçon

Pour le montage physique :
- Avoir un circuit avec potentiomètre fonctionnel prêt pour la démonstration.
- Ouvrir le moniteur série sur votre écran avant l’arrivée des élèves pour qu’ils voient les nombres changer quand vous tournez le bouton.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir le circuit monté à l’avance dans Tinkercad.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

Ouvrez le moniteur série et tournez lentement le bouton. Laissez les élèves regarder les nombres changer en temps réel avant d’expliquer quoi que ce soit.

## Déroulement de la leçon

### Ouverture (5 minutes)

Tournez le bouton de votre circuit déjà monté. La DEL devient plus brillante, puis plus faible.

Demandez : « À la dernière leçon, le bouton nous donnait seulement deux options. Qu’est-ce qui est différent ici? »

Laissez-les comprendre que le changement est graduel : il y a plus de deux options.

### Révision de la leçon 3 (5 minutes)

Petite vérification :
- À quoi sert une résistance de rappel?
- Que renvoie digitalRead?
- Quelle est la différence entre INPUT et OUTPUT?

Si la plupart des élèves s’en souviennent, passez à la suite. Sinon, faites un rappel de 2 minutes avant de continuer.

### Concept : analogique ou numérique (10 minutes)

Le numérique, c’est tout ou rien. Un interrupteur est numérique : allumé ou éteint.

L’analogique, c’est une plage de valeurs. Un gradateur est analogique : n’importe où entre complètement éteint et complètement allumé.

Le bouton de la dernière leçon était numérique. Le potentiomètre est analogique.

Un potentiomètre a trois broches. Les deux broches extérieures sont reliées à l’alimentation et à la masse. La broche du milieu est le curseur. À l’intérieur, il y a une bande de matériau résistif. Quand on tourne le bouton, le curseur se déplace le long de cette bande et change la résistance entre la broche du milieu et chaque broche extérieure. Plus il y a de résistance, moins il y a de tension à la broche du milieu.

L’Arduino lit cette tension et la convertit en un nombre entre 0 et 1023. Complètement à gauche, c’est 0. Complètement à droite, c’est 1023. Cette conversion est faite par le convertisseur analogique-numérique (CAN) intégré à l’Arduino. C’est pourquoi les broches analogiques portent les noms A0 à A5.

À savoir : pour les DEL, analogWrite va seulement de 0 à 255, et non de 0 à 1023. On divise donc la lecture du potentiomètre par 4. C’est le principal calcul de cette leçon.

### Monter le circuit (20 minutes)

Objectif : le potentiomètre contrôle la luminosité de la DEL

Référence du circuit : voir le guide visuel (lesson_04_potentiometer_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Brancher la DEL
- Patte longue reliée à la broche 9 (ce doit être une broche MLI, marquée d’un ~ sur la carte)
- Patte courte reliée au rail de masse par la résistance de 220 Ω

Étape 2 : Placer le potentiomètre sur la plaque d’essai
- Broche extérieure gauche reliée au rail de masse
- Broche extérieure droite reliée au rail 5 V
- Broche du milieu reliée à A0

Étape 3 : Relier le rail de masse à la broche GND et le rail 5 V à la broche 5V de l’Arduino

Étape 4 : Brancher le câble USB

Important : la DEL doit être sur la broche 3, 5, 6, 9, 10 ou 11. Ce sont les broches MLI (modulation de largeur d’impulsion, ou PWM en anglais), marquées d’un ~. Les broches ordinaires peuvent seulement être complètement allumées ou complètement éteintes. Les broches MLI peuvent aussi produire tout ce qu’il y a entre les deux.

#### En version virtuelle (Tinkercad) :

Étape 1 : Ajouter une carte Arduino, une plaque d’essai, une DEL, une résistance de 220 Ω et un potentiomètre

Étape 2 : Brancher la DEL
- Anode reliée à la broche 9
- Cathode reliée à la masse par la résistance

Étape 3 : Brancher le potentiomètre
- Broche gauche reliée à la masse
- Broche droite reliée au 5 V
- Broche du milieu reliée à A0

Étape 4 : Cliquer sur « Code », puis choisir « Texte ».

### Écrire le code ensemble (20 minutes)

Référence du code : voir code_examples/lesson_04_potentiometer/

Faites taper le code ligne par ligne :

```cpp
int potPin = A0;
int ledPin = 9;
int potValue = 0;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  brightness = potValue / 4;
  analogWrite(ledPin, brightness);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  delay(50);
}
```

Passez en revue chaque partie :

analogRead(potPin) : lit la tension à A0 et donne un nombre de 0 à 1023.

potValue / 4 : réduit la plage de 0 à 1023 à une plage de 0 à 255 pour qu’on puisse l’utiliser avec analogWrite.

analogWrite(ledPin, brightness) : contrairement à digitalWrite, qui donne seulement HIGH ou LOW, analogWrite peut prendre n’importe quelle valeur de 0 à 255. C’est ce qui permet à la DEL de baisser d’intensité au lieu d’être seulement complètement allumée ou éteinte.

Serial.begin(9600) et Serial.print : après le téléversement, ouvrez Outils, puis Moniteur série. Tournez le bouton et regardez les nombres changer en temps réel.

Téléversez et testez. Tournez le bouton. La DEL devrait devenir plus brillante et plus faible en douceur.

### Temps d’expérimentation (15 minutes)

Défis :

1. Tournez le bouton jusqu’à ce que le moniteur série affiche environ 512. Quelle luminosité obtenez-vous?
2. Ajoutez une deuxième DEL sur la broche 10 qui fait l’inverse : quand la DEL 1 est brillante, la DEL 2 est faible. (Indice : 255 moins brightness.)
3. (Avancé) Ajoutez une instruction if. Si le potentiomètre est sous 300, la DEL clignote rapidement. S’il est au-dessus de 700, elle clignote lentement. Entre les deux, le potentiomètre contrôle la luminosité normalement.

### Présentation (5 minutes)

Interrogez 2 ou 3 élèves :
- Tourner le bouton et expliquer ce qui se passe à l’intérieur du potentiomètre
- Montrer le moniteur série et expliquer ce que signifient les deux nombres
- Expliquer pourquoi il faut diviser par 4

### Clôture (5 minutes)

Questions de révision :
- Quelle est la différence entre analogRead et digitalRead?
- Pourquoi la DEL doit-elle être sur une broche MLI?
- À quoi sert la division par 4 et pourquoi en a-t-on besoin?

Aperçu de la semaine prochaine : premier projet intégrateur. Les élèves utilisent tout ce qu’ils ont appris aux leçons 1 à 4 pour monter leur propre circuit à partir de zéro.

Rangement :
- Débrancher le câble USB
- Garder le circuit avec potentiomètre; il servira au projet intégrateur

## Évaluation

Pendant la leçon :
- La DEL réagit-elle en douceur au potentiomètre?
- L’élève peut-il expliquer ce que renvoie analogRead?
- L’élève comprend-il pourquoi on divise par 4?

Billet de sortie :
1. Quelle est la plage de valeurs d’analogRead? Quelle est celle d’analogWrite?
2. Qu’est-ce que le moniteur série te montre que tu ne peux pas voir juste en regardant le circuit?
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves font varier la luminosité de la DEL en douceur et savent lire le moniteur série.

## Problèmes fréquents

### La DEL ne baisse pas d’intensité, elle s’allume et s’éteint seulement
- La DEL est sur une broche qui n’est pas MLI
- Déplacer le fil de la DEL sur la broche 9, 10 ou 11

### Le moniteur série affiche 0 tout le temps
- La broche du milieu du potentiomètre n’est pas reliée à A0
- Vérifier précisément le branchement de la broche du milieu

### Les nombres sautent beaucoup
- Mauvais contact sur le potentiomètre
- Appuyer sur les pattes du potentiomètre pour s’assurer qu’elles sont bien enfoncées dans la plaque d’essai

### La DEL reste à pleine luminosité ou complètement éteinte
- Les broches extérieures du potentiomètre sont inversées
- Essayer d’intervertir les connexions de la masse et du 5 V sur les broches extérieures

## Autres situations

Besoin de soutien :
- Les faire se concentrer d’abord sur la variation de luminosité de la DEL, et garder le moniteur série pour quand ça fonctionne
- Brancher le potentiomètre à l’avance et les laisser se concentrer sur le code

Avancé :
- Que se passe-t-il si on utilise map() au lieu de diviser par 4? Cherchez la fonction map() dans la documentation de référence Arduino.
- Pouvez-vous utiliser le potentiomètre pour contrôler le delay d’une DEL clignotante au lieu de sa luminosité?

## Notes pour l’enseignant

Le moniteur série est le moment fort de cette leçon. Voir des nombres changer en temps réel quand on tourne un bouton physique fait déclic chez la plupart des élèves, bien plus que de simplement voir la DEL baisser d’intensité. Ne sautez pas cette partie.

Les broches MLI sont l’erreur de branchement la plus fréquente. Circulez dans la classe et vérifiez que chaque élève a sa DEL sur une broche MLI avant de téléverser le code.

Durée :
- Concept : 10 min
- Montage : 20 min
- Code : 20 min
- Expérimentation : 15 min
- Marge : 15 min pour le dépannage

Préparation :
- Tester le circuit avec potentiomètre avant la séance
- Avoir le moniteur série ouvert et prêt à montrer

*Fin de la leçon 4*
