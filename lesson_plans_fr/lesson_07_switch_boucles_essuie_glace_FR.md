# Leçon 7 : Instructions switch, boucles et essuie-glace

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçon 6 (Servomoteur). Les élèves doivent avoir un circuit avec servomoteur fonctionnel.

## Aperçu

Aucun nouveau composant dans cette leçon. Celle-ci porte entièrement sur la programmation. Les élèves apprennent les instructions switch, les boucles for et les boucles while en montant un circuit d’essuie-glace à quatre modes.

## Objectifs d’apprentissage

Les élèves apprendront :
- Ce qu’est une instruction switch et quand l’utiliser plutôt que des instructions if
- Comment fonctionne une boucle for et quand l’utiliser
- Comment fonctionne une boucle while et quand l’utiliser
- Comment utiliser millis() pour mesurer le temps sans arrêter tout le programme
- Pourquoi la facilité d’utilisation est importante quand on conçoit quoi que ce soit

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 1 servomoteur
- 1 condensateur de 100 microfarads (polarisé)
- 1 potentiomètre
- 1 bouton-poussoir
- 1 résistance de 10 kΩ (résistance de rappel pour le bouton)
- 1 DEL
- 1 résistance de 220 Ω (pour la DEL)
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad
- Aucun condensateur n’est nécessaire dans Tinkercad

### La physique (gardons ça simple)

Aucun nouveau composant aujourd’hui. Tout ce qu’on utilise vient des leçons précédentes.

Le condensateur est encore nécessaire pour protéger le circuit quand le servomoteur bouge. (Montage physique seulement)

## Avant la leçon

Pour le montage physique :
- Avoir un circuit d’essuie-glace déjà monté et fonctionnel pour montrer les quatre modes.
- Vérifier que le bouton change correctement de mode avant l’arrivée des élèves.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir le circuit d’essuie-glace monté à l’avance dans Tinkercad.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

Quand vous présentez l’instruction switch, demandez aux élèves de penser à un exemple de la vie de tous les jours avant de leur donner celui du restaurant. Voyez ce qu’ils proposent.

## Déroulement de la leçon

### Ouverture (5 minutes)

Montrez le circuit d’essuie-glace déjà monté. Appuyez une fois sur le bouton : l’essuie-glace se met à bouger à vitesse constante. Appuyez de nouveau : la vitesse change selon le potentiomètre. Appuyez encore : la DEL s’allume, l’essuie-glace fait 5 allers-retours, puis s’arrête.

Demandez : « Selon vous, comment le code sait-il dans quel mode il doit être? »

Laissez-les deviner. Dites-leur ensuite qu’ils vont apprendre exactement comment.

### Révision de la leçon 6 (5 minutes)

Petite vérification :
- Que fait myServo.write()?
- Que fait map()?
- Quels sont les trois fils d’un servomoteur?

Si la plupart des élèves s’en souviennent, passez à la suite. Sinon, faites un rappel de 2 minutes avant de continuer.

### Concept : les instructions switch (10 minutes)

Une instruction switch a un certain nombre de cas, ou de modes. Chaque cas fait quelque chose de différent. Quand le mode change, le comportement change.

Pensez à un menu au restaurant. Si on choisit le premier plat, c’est le cas 0 : la cuisine fait une chose. Si on choisit le deuxième plat, c’est le cas 1 : la cuisine fait quelque chose de complètement différent. C’est ainsi que fonctionne une instruction switch.

On pourrait faire la même chose avec une série d’instructions if et else, mais switch est plus clair et plus facile à gérer. Imaginez 5 instructions if et else comparées à 5 cas dans un switch. Juste les accolades de la version if et else seraient un vrai fouillis.

Voici la structure de base :

```cpp
switch (mode) {
  case 0:
    // faire quelque chose
    break;
  case 1:
    // faire quelque chose de différent
    break;
}
```

Le break à la fin de chaque cas indique à l’Arduino de s’arrêter et de ne pas continuer dans le cas suivant.

### Concept : les boucles for et while (10 minutes)

La boucle for :

Une boucle for s’exécute un nombre précis de fois. On lui donne une valeur de départ, une condition d’arrêt et de combien augmenter à chaque tour.

```cpp
for (int i = 0; i < 5; i++) {
  // ceci s'exécute 5 fois
}
```

Elle commence à 0, continue tant que i est plus petit que 5, et ajoute 1 à chaque tour. Utilisez une boucle for quand vous savez exactement combien de fois une action doit se répéter.

La boucle while :

Une boucle while s’exécute tant qu’une condition est vraie.

```cpp
while (condition == true) {
  // continue jusqu'à ce que la condition devienne fausse
}
```

Utilisez une boucle while quand vous ne savez pas d’avance combien de fois elle s’exécutera. Par exemple : continuer à clignoter jusqu’à ce qu’on appuie sur le bouton.

La différence :
- Boucle for : à utiliser quand on connaît le nombre exact de répétitions
- Boucle while : à utiliser quand on ne le connaît pas, et que quelque chose d’autre l’arrêtera

Un point à toujours surveiller avec les deux : assurez-vous que la condition finira par devenir fausse. Si elle ne le devient jamais, la boucle tourne à l’infini et le programme gèle. C’est ce qu’on appelle une boucle infinie.

### Monter le circuit (15 minutes)

Objectif : un essuie-glace à 4 modes contrôlé par un bouton

Référence du circuit : voir le guide visuel (lesson_07_windshield_wiper_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Brancher le condensateur
- Patte négative (côté de la bande) reliée au rail de masse
- Patte positive reliée au rail 5 V

Étape 2 : Brancher le servomoteur
- Fil brun ou noir relié au rail de masse
- Fil rouge relié au rail 5 V
- Fil de signal relié à la broche 9

Étape 3 : Brancher le potentiomètre
- Broche gauche reliée au rail de masse
- Broche droite reliée au rail 5 V
- Broche du milieu reliée à A0

Étape 4 : Brancher le bouton
- Une patte reliée au 5 V
- L’autre patte reliée à la broche 7
- Résistance de 10 kΩ de la broche 7 à la masse

Étape 5 : Brancher la DEL
- Patte longue reliée à la broche 4
- Patte courte reliée à la masse par la résistance de 220 Ω

Étape 6 : Brancher le câble USB

#### En version virtuelle (Tinkercad) :

Étape 1 : Ajouter une carte Arduino, une plaque d’essai, un servomoteur, un potentiomètre, un bouton, une DEL, une résistance de 220 Ω et une résistance de 10 kΩ (aucun condensateur)

Étape 2 : Brancher le servomoteur
- Fil de signal relié à la broche 9, alimentation au 5 V, masse à la masse

Étape 3 : Brancher le potentiomètre
- Broche gauche reliée à la masse, broche droite au 5 V, broche du milieu à A0

Étape 4 : Brancher le bouton
- Une borne reliée au 5 V, l’autre à la broche 7, résistance de 10 kΩ de la broche 7 à la masse

Étape 5 : Brancher la DEL
- Anode reliée à la broche 4, cathode reliée à la masse par la résistance de 220 Ω

### Écrire le code ensemble (25 minutes)

Référence du code : voir code_examples/lesson_07_windshield_wiper/

C’est le code le plus complexe qu’on a fait jusqu’à maintenant. Avancez lentement.

```cpp
#include <Servo.h>

Servo myServo;

int potPin = A0;
int buttonPin = 7;
int ledPin = 4;
int servoPin = 9;

int mode = 0;
int servoAngle = 0;
int delayTime = 1000;
int potValue = 0;
bool buttonPressed = false;
unsigned long lastTime = 0;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
    buttonPressed = true;
    mode = (mode + 1) % 4;
  }
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = false;
  }

  switch (mode) {
    case 0:
      servoAngle = 0;
      delayTime = 1000;
      break;

    case 1:
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      delayTime = 1000;
      break;

    case 2:
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      potValue = analogRead(potPin);
      delayTime = map(potValue, 0, 1023, 100, 2000);
      break;

    case 3:
      digitalWrite(ledPin, HIGH);
      for (int i = 0; i < 5; i++) {
        myServo.write(0);
        delay(1000);
        myServo.write(179);
        delay(1000);
      }
      digitalWrite(ledPin, LOW);
      mode = 0;
      break;
  }

  myServo.write(servoAngle);

  lastTime = millis();
  while (millis() - lastTime < delayTime) {
    if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
      buttonPressed = true;
      mode = (mode + 1) % 4;
      break;
    }
    if (digitalRead(buttonPin) == LOW) {
      buttonPressed = false;
    }
  }
}
```

Passez en revue les parties importantes :

mode = (mode + 1) % 4 : fait passer le mode de 0 à 3, puis revenir à 0. Le % est l’opérateur modulo : il donne le reste d’une division. 4 % 4 donne 0, donc après le mode 3, on revient au mode 0.

switch (mode) : vérifie le mode actuel et exécute le cas correspondant.

Le cas 3 utilise une boucle for, parce qu’on sait exactement combien d’allers-retours on veut que l’essuie-glace fasse : 5. Une fois la boucle terminée, le mode revient à 0 et la DEL s’éteint.

La boucle while à la fin : au lieu d’utiliser delay(), qui arrêterait tout le programme et rendrait le bouton insensible, on utilise millis() pour mesurer le temps tout en continuant à vérifier le bouton. C’est la solution au problème de bouton que vous avez peut-être remarqué dans les leçons précédentes.

Téléversez et testez. Appuyez sur le bouton pour passer d’un mode à l’autre.

### Temps d’expérimentation (10 minutes)

Défis :

1. Modifiez le cas 3 pour que l’essuie-glace fasse 10 allers-retours au lieu de 5.
2. Ajoutez un cinquième mode où la DEL clignote pendant que le servomoteur balaie d’un côté à l’autre.
3. (Avancé) Modifiez le cas 2 pour que le potentiomètre contrôle l’angle du balayage plutôt que la vitesse. (Indice : utilisez map() pour convertir la lecture du potentiomètre en angle du servomoteur, et non en délai.)

### Présentation (5 minutes)

Interrogez 2 ou 3 élèves :
- Montrer les quatre modes en fonctionnement
- Expliquer en mots simples ce que fait la boucle for du cas 3
- Expliquer pourquoi on utilise millis() au lieu de delay()

### Clôture (5 minutes)

Questions de révision :
- Quelle est la différence entre une boucle for et une boucle while?
- Que se passe-t-il si la condition de votre boucle ne devient jamais fausse?
- Pourquoi le bouton réagit-il mieux dans ce code que dans les leçons précédentes?

Rangement :
- Débrancher le câble USB
- Garder le circuit si possible; certains composants serviront encore

## Évaluation

Pendant la leçon :
- L’élève peut-il expliquer quand utiliser une boucle for plutôt qu’une boucle while?
- Les quatre modes fonctionnent-ils correctement?
- L’élève peut-il expliquer ce que fait mode = (mode + 1) % 4?

Billet de sortie :
1. Écris une boucle for qui s’exécute exactement 3 fois.
2. Qu’est-ce qu’une boucle infinie et comment l’éviter?
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves ont les quatre modes fonctionnels et peuvent expliquer la différence entre les boucles for et while.

## Problèmes fréquents

### Le bouton fait passer plusieurs modes d’un coup
- Problème de rebond du bouton
- La variable buttonPressed dans le code règle ce problème : vérifier que les élèves l’ont copiée correctement

### Le mode 3 reste bloqué et ne revient jamais au mode 0
- Vérifier que mode = 0 se trouve dans le cas 3, après la boucle for
- S’assurer que le break n’arrête pas le cas trop tôt

### Le servomoteur ne bouge dans aucun mode
- Vérifier que myServo.attach() est dans setup
- Vérifier que le fil de signal est sur la broche 9

### La boucle while gèle le programme
- La condition ne devient jamais fausse
- Vérifier que buttonPressed revient à false quand on relâche le bouton

## Autres situations

Besoin de soutien :
- Faire fonctionner les modes 0 et 1 avant de toucher aux modes 2 et 3
- Passer l’instruction switch en revue un cas à la fois

Avancé :
- Pouvez-vous ajouter un affichage qui montre le numéro du mode actuel?
- Pouvez-vous faire en sorte que, dans le cas 2, la vitesse du balayage augmente quand on tourne le bouton dans un sens et diminue quand on le tourne dans l’autre?

## Notes pour l’enseignant

L’explication de millis() est le concept le plus important de cette leçon. Les élèves auront remarqué dans les leçons précédentes que delay() rend le bouton insensible. Cette leçon explique pourquoi et montre la solution. Assurez-vous que ce point est bien compris.

Les instructions switch sont plus claires que les enchaînements de if et else, mais les élèves doivent voir les deux côte à côte pour l’apprécier. Si vous avez le temps, écrivez d’abord la même logique avec des instructions if et else, puis montrez la version avec switch. La différence saute aux yeux.

La boucle for du cas 3 est un parfait exemple de situation où utiliser une boucle for plutôt qu’une boucle while : on sait exactement combien d’allers-retours on veut que l’essuie-glace fasse. Soulignez-le explicitement.

Note sur le cas 3 : ce mode utilise volontairement delay() dans la boucle for, donc le bouton ne réagira pas pendant environ 10 secondes. Si un élève le remarque et pose la question, c’est bon signe. Dites-lui qu’il a trouvé exactement le problème que millis() règle, et demandez-lui comment il réécrirait le cas 3 pour que le bouton reste réactif. C’est un excellent défi supplémentaire.

Durée :
- Ouverture : 5 min
- Révision : 5 min
- Concept switch : 10 min
- Concept for et while : 10 min
- Montage : 15 min
- Code : 25 min
- Expérimentation : 10 min
- Présentation : 5 min
- Clôture : 5 min
- Marge : 5 min

Préparation :
- Tester les quatre modes avant la séance
- Avoir le circuit déjà branché pour une démonstration rapide

*Fin de la leçon 7*
