# Leçon 6 : Servomoteur

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçon 4 (Potentiomètre). Les élèves doivent être à l’aise avec analogRead et les variables.

## Aperçu

Jusqu’à maintenant, toutes les leçons portaient sur la lumière. Dans cette leçon, quelque chose bouge enfin. Les élèves branchent un servomoteur et utilisent un potentiomètre pour contrôler l’angle vers lequel il pointe.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment brancher un servomoteur sur une plaque d’essai ou dans Tinkercad
- À quoi sert un condensateur et pourquoi le servomoteur en a besoin (montage physique seulement)
- Comment importer et utiliser une bibliothèque dans le logiciel Arduino IDE
- Comment utiliser la fonction map() pour convertir une lecture du potentiomètre en angle du servomoteur
- Comment contrôler la position du servomoteur avec un potentiomètre et un bouton

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 1 servomoteur
- 1 condensateur de 100 microfarads (polarisé)
- 1 potentiomètre
- 1 bouton-poussoir
- 1 résistance de 10 kΩ (résistance de rappel pour le bouton)
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad
- Aucun condensateur n’est nécessaire dans Tinkercad

### La physique (gardons ça simple)

Un servomoteur tourne jusqu’à un angle précis et s’y maintient, n’importe où entre 0 et 180 degrés.

Il a trois fils : la masse, l’alimentation et le signal. Le fil de signal lui indique où aller.

Quand un servomoteur bouge, il tire beaucoup de courant très rapidement. Un condensateur emmagasine une petite charge et la libère quand le servomoteur en a besoin, ce qui garde le reste du circuit stable. (Montage physique seulement)

Les condensateurs sont polarisés. La patte négative va à la masse. S’il est branché à l’envers, il peut être endommagé.

## Avant la leçon

Pour le montage physique :
- Tester votre circuit avec servomoteur avant l’arrivée des élèves; les servomoteurs peuvent être capricieux.
- Avoir déjà importé la bibliothèque Servo sur l’ordinateur de démonstration.
- S’assurer que les condensateurs sont dans les trousses et vérifier leur polarité avant que les élèves les branchent.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir le circuit avec servomoteur monté à l’avance dans Tinkercad.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

Ne dites rien quand vous montrez la démonstration pour la première fois. Tournez simplement le bouton du potentiomètre et laissez-les regarder le servomoteur bouger. La réaction est toujours meilleure quand ils ne savent pas à quoi s’attendre.

## Déroulement de la leçon

### Ouverture (5 minutes)

Branchez votre circuit déjà monté et tournez le potentiomètre. Le bras du servomoteur balaie d’un côté à l’autre.

Ne dites rien. Laissez-les simplement regarder.

Ensuite, demandez : « Qu’est-ce qui est différent ici, comparé à tout ce qu’on a monté jusqu’à maintenant? »

Ils diront que ça bouge. Partez de là.

### Révision de la leçon 4 (5 minutes)

Petite vérification :
- Que renvoie analogRead?
- Pourquoi divise-t-on par 4 quand on utilise analogWrite?
- Qu’est-ce qu’une broche MLI (PWM)?

Si la plupart des élèves s’en souviennent, passez à la suite. Sinon, faites un rappel de 2 minutes avant de continuer.

### Concept : le fonctionnement d’un servomoteur (8 minutes)

Un servomoteur n’est pas comme un moteur ordinaire qui tourne sans arrêt. Il tourne jusqu’à un angle précis et s’y maintient, n’importe où entre 0 et 180 degrés, selon le signal qu’on lui envoie.

À l’intérieur d’un servomoteur, il y a un petit moteur, un ensemble d’engrenages et un capteur de position. Le capteur de position indique au servomoteur où il se trouve. Le servomoteur s’ajuste continuellement jusqu’à ce qu’il atteigne l’angle demandé.

Les servomoteurs ont trois fils :
- Brun ou noir : masse
- Rouge : alimentation (5 V)
- Orange, jaune ou blanc : signal (relié à une broche de l’Arduino)

Pour le montage physique seulement, le condensateur :

Quand un servomoteur bouge, il tire beaucoup de courant très rapidement. Cette demande soudaine peut faire baisser la tension fournie au reste du circuit et causer des comportements étranges. Un condensateur règle ce problème. Il emmagasine une petite charge et la libère dès que le servomoteur a besoin de plus de puissance.

Les condensateurs sont polarisés : ils ont une patte positive et une patte négative. La patte négative est indiquée par une bande sur le côté du condensateur. La patte négative va à la masse. Si on le branche à l’envers, il peut être endommagé.

### Monter le circuit (20 minutes)

Objectif : le potentiomètre contrôle l’angle du servomoteur, et le bouton envoie le servomoteur directement à 180 degrés

Référence du circuit : voir le guide visuel (lesson_06_servo_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Brancher le potentiomètre
- Broche gauche reliée au rail de masse
- Broche droite reliée au rail 5 V
- Broche du milieu reliée à A0

Étape 2 : Brancher le bouton
- Une patte reliée au 5 V
- L’autre patte reliée à la broche 7
- Résistance de 10 kΩ de la broche 7 à la masse

Étape 3 : Brancher le condensateur (montage physique seulement)
- Patte négative (côté de la bande) reliée au rail de masse
- Patte positive reliée au rail 5 V
- Le placer près de l’endroit où le servomoteur est branché

Étape 4 : Brancher le servomoteur
- Fil brun ou noir relié au rail de masse
- Fil rouge relié au rail 5 V
- Fil de signal relié à la broche 9

Étape 5 : Brancher le câble USB

Vérifiez deux fois la polarité du condensateur avant de mettre sous tension : le négatif à la masse, le positif au 5 V.

#### En version virtuelle (Tinkercad) :

Étape 1 : Ajouter une carte Arduino, une plaque d’essai, un potentiomètre, un bouton-poussoir et un servomoteur (aucun condensateur nécessaire)

Étape 2 : Brancher le potentiomètre
- Broche gauche reliée à la masse
- Broche droite reliée au 5 V
- Broche du milieu reliée à A0

Étape 3 : Brancher le bouton
- Une borne reliée au 5 V
- L’autre borne reliée à la broche 7
- Résistance de 10 kΩ de la broche 7 à la masse

Étape 4 : Brancher le servomoteur
- Fil noir relié à la masse
- Fil rouge relié au 5 V
- Fil de signal relié à la broche 9

### Écrire le code ensemble (20 minutes)

Référence du code : voir code_examples/lesson_06_servo_motor/

Avant de taper quoi que ce soit, expliquez que le servomoteur a besoin d’une bibliothèque. Une bibliothèque, c’est du code supplémentaire que quelqu’un d’autre a déjà écrit et qui nous donne de nouvelles fonctions à utiliser. L’Arduino n’inclut pas le contrôle des servomoteurs par défaut, alors il faut l’importer.

Allez dans Croquis, puis Inclure une bibliothèque, puis cherchez Servo et ajoutez-la. Vous pouvez aussi simplement taper la ligne #include en haut du code.

Faites taper le code ligne par ligne :

```cpp
#include <Servo.h>

Servo myServo;

int potPin = A0;
int buttonPin = 7;
int potValue = 0;
int angle = 0;
int buttonState = 0;

void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    myServo.write(180);
  } else {
    potValue = analogRead(potPin);
    angle = map(potValue, 0, 1023, 0, 180);
    myServo.write(angle);
  }

  Serial.print("Angle: ");
  Serial.println(angle);

  delay(15);
}
```

Passez en revue chaque nouvel élément :

#include <Servo.h> : importe la bibliothèque Servo et nous donne les fonctions pour contrôler le servomoteur.

Servo myServo : crée un objet servomoteur. C’est comme donner un nom au servomoteur pour pouvoir lui parler dans le code.

myServo.attach(9) : indique à l’Arduino que notre servomoteur est branché sur la broche 9.

map(potValue, 0, 1023, 0, 180) : prend un nombre dans une plage et le convertit dans une autre plage. Le potentiomètre va de 0 à 1023, et on veut un angle de 0 à 180. map() fait cette conversion proprement.

myServo.write(angle) : demande au servomoteur de se déplacer jusqu’à cet angle et de s’y maintenir.

Téléversez et testez. Tournez le potentiomètre : le servomoteur devrait le suivre en douceur. Appuyez sur le bouton : le servomoteur va directement à 180.

### Temps d’expérimentation (15 minutes)

Défis :

1. Faites en sorte que le bouton envoie le servomoteur à 0 degré au lieu de 180. Quand on le relâche, le servomoteur revient là où pointe le potentiomètre.
2. Ajoutez une autre position. Chaque appui sur le bouton fait passer le servomoteur à 0, puis à 90, puis à 180, une position à la fois. (Indice : il vous faut une variable pour savoir à quelle position vous êtes rendus.)
3. (Avancé) Faites balayer le servomoteur automatiquement d’un côté à l’autre, sans le potentiomètre. Utilisez une boucle for. Ajoutez ensuite le bouton pour mettre le balayage en pause et le reprendre.

### Présentation (5 minutes)

Interrogez 2 ou 3 élèves :
- Tourner le potentiomètre et expliquer ce que fait map()
- Expliquer dans leurs mots à quoi sert le condensateur (montage physique)
- Montrer le comportement du bouton

### Clôture (5 minutes)

Questions de révision :
- Qu’est-ce qu’une bibliothèque et pourquoi en a-t-on besoin pour le servomoteur?
- Que fait map() et pourquoi est-ce utile?
- Que se passerait-il si on enlevait le condensateur? (montage physique)

Rangement :
- Débrancher le câble USB
- Retirer le servomoteur avec soin : les fils se débranchent facilement
- Remettre les condensateurs dans le bac avec soin et vérifier que les pattes ne sont pas pliées

## Évaluation

Pendant la leçon :
- Le servomoteur réagit-il en douceur au potentiomètre?
- L’élève peut-il expliquer ce que fait map()?
- Le condensateur est-il branché correctement? (montage physique)

Billet de sortie :
1. Explique en mots simples ce que fait map(potValue, 0, 1023, 0, 180).
2. Pourquoi le servomoteur a-t-il besoin d’un condensateur, mais pas la DEL? (montage physique)
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves ont un servomoteur qui réagit au potentiomètre et peuvent expliquer map().

## Problèmes fréquents

### Le servomoteur tremble sans arrêt et ne garde pas sa position
- Mauvais contact sur le fil de signal
- Vérifier que le fil de signal est bien enfoncé dans la broche 9

### Le servomoteur va seulement à une extrémité et y reste
- Les broches extérieures du potentiomètre sont inversées
- Essayer d’intervertir les connexions de la masse et du 5 V sur les broches extérieures

### L’Arduino redémarre quand le servomoteur bouge (montage physique)
- Condensateur absent ou mal branché
- Vérifier la polarité et la connexion du condensateur

### Le servomoteur ne réagit pas du tout
- La bibliothèque n’a pas été importée
- Vérifier que le numéro de broche dans myServo.attach() correspond au montage

### Dans Tinkercad, le servomoteur bouge par à-coups au lieu de balayer
- delay(15) est trop court ou absent
- S’assurer que le delay est à la fin de la boucle

## Autres situations

Besoin de soutien :
- Laisser tomber le bouton et faire d’abord fonctionner le contrôle du servomoteur par le potentiomètre
- Brancher le condensateur à l’avance pour les élèves du montage physique qui sont nerveux à propos de la polarité

Avancé :
- Pouvez-vous utiliser le potentiomètre pour contrôler la vitesse d’un balayage automatique au lieu de l’angle?
- Pouvez-vous combiner le servomoteur et une DEL pour que la luminosité change selon l’angle du servomoteur?

## Notes pour l’enseignant

Le moment d’ouverture compte. N’expliquez pas le servomoteur avant de le montrer en mouvement. Laissez-les le voir d’abord.

map() est le concept qui reste de cette leçon. On le retrouve partout en robotique. Prenez plus de temps pour l’expliquer au besoin.

Pour le montage physique : vérifiez chaque condensateur avant la mise sous tension. Un condensateur branché à l’envers peut éclater, et c’est impressionnant même si ce n’est pas dangereux. Circulez et vérifiez la polarité sur chaque carte avant que les élèves branchent le câble USB.

Durée :
- Ouverture : 5 min
- Révision : 5 min
- Concept : 8 min
- Montage : 20 min
- Code : 20 min
- Expérimentation : 15 min
- Présentation : 5 min
- Clôture : 5 min
- Marge : 7 min

Préparation :
- Tester le circuit avec servomoteur avant la séance
- Avoir déjà importé la bibliothèque Servo sur l’ordinateur de démonstration

*Fin de la leçon 6*
