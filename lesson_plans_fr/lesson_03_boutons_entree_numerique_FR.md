# Leçon 3 : Boutons et entrée numérique

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçon 2 (Motifs de DEL). Les élèves doivent avoir un circuit fonctionnel avec des DEL en parallèle.

## Aperçu

À la dernière leçon, les DEL faisaient simplement ce que le code leur disait de faire. Dans cette leçon, le circuit réagit enfin à quelque chose. Les élèves ajoutent un bouton et écrivent du code qui y répond.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment brancher un bouton-poussoir sur une plaque d’essai ou dans Tinkercad
- À quoi sert une résistance de rappel (pull-down) et pourquoi elle est nécessaire
- Comment utiliser digitalRead pour vérifier l’état du bouton dans le code
- Comment écrire une instruction if qui contrôle une DEL selon l’état du bouton

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 1 DEL (n’importe quelle couleur)
- 1 résistance de 220 Ω (pour la DEL)
- 1 bouton-poussoir
- 1 résistance de 10 kΩ (résistance de rappel, pour le bouton)
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad

### La physique (gardons ça simple)

Un bouton, c’est simplement une coupure dans un circuit. Quand on appuie, la coupure se ferme et l’électricité circule. Quand on relâche, la coupure s’ouvre et l’électricité s’arrête.

Sans résistance de rappel, la broche est « flottante » et capte du bruit électrique aléatoire dans l’environnement. La DEL pourrait clignoter ou s’allumer toute seule.

La résistance de rappel de 10 kΩ donne à la broche un chemin clair vers la masse quand le bouton n’est pas enfoncé. Ainsi, la broche lit toujours LOW tant qu’on n’appuie pas vraiment sur le bouton.

## Avant la leçon

Pour le montage physique :
- Avoir un circuit avec bouton déjà monté et fonctionnel à montrer.
- Avoir un deuxième circuit prêt, sans résistance de rappel, pour montrer à quoi ressemble une broche flottante.
- Vérifier que le bouton est bien détecté avant l’arrivée des élèves.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir un circuit avec bouton fonctionnel monté à l’avance dans Tinkercad.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

Montrez d’abord le circuit sans résistance de rappel. Laissez les élèves voir le clignotement aléatoire avant d’expliquer pourquoi il se produit.

## Déroulement de la leçon

### Ouverture (5 minutes)

Montrez le circuit déjà monté. Appuyez sur le bouton : la DEL s’allume. Relâchez-le : la DEL s’éteint.

Demandez : « Selon vous, que se passe-t-il à l’intérieur du bouton quand on appuie dessus? »

Laissez-les deviner. La plupart diront que l’électricité peut passer, ce qui est juste. Partez de là.

### Révision de la leçon 2 (5 minutes)

Petite vérification :
- Quelle est la différence entre un circuit en série et un circuit en parallèle?
- Que fait pinMode?
- Que fait digitalWrite(13, HIGH)?

Si la plupart des élèves s’en souviennent, passez à la suite. Sinon, faites un rappel de 2 minutes avant de continuer.

### Concept : le fonctionnement d’un bouton (8 minutes)

Le bouton est le composant d’entrée le plus simple. Quand on appuie dessus, on ferme physiquement une coupure dans le circuit. L’électricité peut circuler. Quand on le relâche, la coupure s’ouvre de nouveau et l’électricité s’arrête.

Dessinez ceci ou montrez-le au projecteur :

```
NON ENFONCÉ :   Broche 8 ---[coupure]--- 5 V   (aucune connexion, aucun signal)
ENFONCÉ :       Broche 8 --------------- 5 V   (connecté, le signal passe à HIGH)
```

L’Arduino lit LOW quand le bouton n’est pas enfoncé et HIGH quand il l’est.

Voici maintenant le problème. Sans résistance de rappel, la broche est flottante : elle n’est reliée à rien quand le bouton est relâché. Une broche flottante capte du bruit électrique aléatoire dans l’environnement et donne des lectures imprévisibles. La DEL pourrait clignoter ou s’allumer au hasard, même quand personne n’appuie sur rien.

Si vous en avez un de prêt, montrez le circuit sans résistance de rappel. Laissez-les voir le comportement aléatoire. Ensuite, montrez ce qui se passe quand on ajoute la résistance. La différence est évidente.

La solution : une résistance de rappel de 10 kΩ qui relie la broche à la masse. Quand le bouton n’est pas enfoncé, la broche a un chemin clair vers la masse et lit LOW. Quand le bouton est enfoncé, les 5 V l’emportent sur la résistance et la broche lit HIGH. Le signal est maintenant prévisible.

### Monter le circuit (20 minutes)

Objectif : une DEL contrôlée par un bouton

Référence du circuit : voir le guide visuel (lesson_03_button_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Placer la DEL sur la plaque d’essai
- Patte longue dans la rangée 5, côté gauche
- Patte courte dans la rangée 5, côté droit
- Résistance de 220 Ω de la patte courte au rail de masse
- Fil de connexion de la patte longue à la broche 13

Étape 2 : Placer le bouton sur la plaque d’essai
- Les pattes du bouton de part et d’autre de la séparation centrale de la plaque d’essai
- Une patte reliée au rail 5 V
- La patte opposée reliée à la broche 8, et aussi à la masse par la résistance de 10 kΩ

Étape 3 : Relier le rail de masse à la broche GND de l’Arduino

Étape 4 : Relier le rail 5 V à la broche 5V de l’Arduino

Étape 5 : Brancher le câble USB

À surveiller : les élèves branchent souvent les deux pattes du bouton du même côté de la séparation de la plaque d’essai. Le bouton sera alors toujours lu comme enfoncé. Assurez-vous que les pattes chevauchent la séparation.

#### En version virtuelle (Tinkercad) :

Étape 1 : Ajouter une carte Arduino Uno, une plaque d’essai, une DEL, une résistance de 220 Ω, un bouton-poussoir et une résistance de 10 kΩ

Étape 2 : Brancher la DEL
- Anode de la DEL reliée à la broche 13
- Cathode de la DEL reliée à la résistance de 220 Ω
- Résistance reliée au rail de masse

Étape 3 : Brancher le bouton
- Une borne reliée au 5 V
- La rangée de cette même borne reliée à la broche 8
- La rangée de la broche 8 reliée aussi à la masse par la résistance de 10 kΩ
- L’autre borne reliée à la masse

Étape 4 : Cliquer sur « Code », puis choisir « Texte ».

### Écrire le code ensemble (20 minutes)

Référence du code : voir code_examples/lesson_03_button_led/

Faites taper le code avec la classe, ligne par ligne :

```cpp
int buttonPin = 8;
int ledPin = 13;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

Passez en revue chaque partie :

Les variables en haut : on donne un nom à nos broches pour que le code soit facile à lire. Si on déplace le bouton sur une autre broche, on change un seul nombre en haut au lieu de chercher partout dans le code.

pinMode(buttonPin, INPUT) : cette fois, on déclare une broche comme ENTRÉE (INPUT) plutôt que comme SORTIE (OUTPUT). L’Arduino écoute cette broche au lieu d’y envoyer des signaux.

digitalRead(buttonPin) : lit si la broche est à HIGH ou à LOW en ce moment et enregistre le résultat dans buttonState.

L’instruction if : si le bouton est enfoncé, on allume la DEL. Sinon, on l’éteint. C’est la première fois que le code prend une décision en fonction de quelque chose qui se passe dans le monde réel.

Téléversez et testez. Bouton enfoncé : DEL allumée. Bouton relâché : DEL éteinte.

### Temps d’expérimentation (15 minutes)

Défis :

1. Inversez le comportement. Faites en sorte que la DEL soit ALLUMÉE quand le bouton n’est PAS enfoncé, et ÉTEINTE quand il l’est.
2. Ajoutez une deuxième DEL. Quand le bouton est enfoncé, la DEL 1 s’allume et la DEL 2 s’éteint. Quand il est relâché, c’est l’inverse.
3. (Avancé) Pouvez-vous faire clignoter la DEL tant que le bouton est maintenu enfoncé? (Indice : placez un delay à l’intérieur de l’instruction if.)

### Présentation (5 minutes)

Interrogez 2 ou 3 élèves :
- Montrer leur circuit fonctionnel
- Pointer la résistance de rappel et expliquer dans leurs mots à quoi elle sert
- Expliquer ce que fait digitalRead

### Clôture (5 minutes)

Questions de révision :
- Qu’arrive-t-il à une broche sans résistance de rappel?
- Quelle est la différence entre INPUT et OUTPUT dans pinMode?
- Que renvoie digitalRead?

Aperçu de la semaine prochaine : le potentiomètre. Au lieu d’obtenir seulement HIGH ou LOW, vous obtiendrez un nombre de 0 à 1023 qui change quand on tourne un bouton rotatif.

Rangement :
- Débrancher le câble USB
- Garder les circuits montés; le bouton reste pour la prochaine leçon

## Évaluation

Pendant la leçon :
- L’élève a-t-il branché correctement la résistance de rappel?
- Le bouton contrôle-t-il la DEL comme prévu?
- L’élève peut-il expliquer à quoi sert la résistance de rappel?

Billet de sortie :
1. Dessine de mémoire le circuit du bouton, y compris la résistance de rappel.
2. Que se passerait-il si tu enlevais la résistance de rappel?
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves ont un circuit avec bouton fonctionnel et peuvent expliquer pourquoi la résistance de rappel est là.

## Problèmes fréquents

### Le bouton lit toujours HIGH
- Les deux pattes du bouton sont du même côté de la séparation de la plaque d’essai
- S’assurer que le bouton chevauche la séparation centrale

### Le bouton ne lit jamais HIGH
- La patte du bouton n’est pas reliée au 5 V
- Vérifier le fil entre le rail 5 V et la borne du bouton

### La DEL clignote au hasard quand le bouton n’est pas enfoncé
- Résistance de rappel absente ou mal branchée
- Vérifier que la résistance de 10 kΩ relie la broche 8 à la masse

### Le code compile, mais rien ne se passe
- Vérifier que les numéros de broches dans le code correspondent au montage
- S’assurer que pinMode indique INPUT pour la broche du bouton, et non OUTPUT

## Autres situations

Besoin de soutien :
- Brancher le bouton à l’avance pour eux et les laisser se concentrer sur le code
- Utiliser un fil de connexion d’une autre couleur pour la résistance de rappel afin qu’elle soit facile à repérer

Avancé :
- Pouvez-vous faire en sorte que le bouton allume et éteigne la DEL en alternance au lieu de devoir le maintenir enfoncé? (La DEL reste allumée après un appui et s’éteint au suivant.)
- Que se passe-t-il si on utilise INPUT_PULLUP au lieu de INPUT et qu’on retire la résistance physique?

## Notes pour l’enseignant

La démonstration de la résistance de rappel est le moment le plus important de cette leçon. Montez un circuit sans résistance et montrez d’abord le comportement aléatoire. Les élèves retiennent beaucoup mieux le problème quand ils le voient avant d’apprendre la solution.

Le défi de l’alternance (allumer et éteindre à chaque appui) est plus difficile qu’il en a l’air. Ne poussez pas les élèves vers ce défi à moins qu’ils aient terminé tout le reste en avance. Il faut garder en mémoire un état d’une boucle à l’autre, ce qui est un nouveau concept.

Durée :
- Concept et démonstration : 13 min
- Montage : 20 min
- Code : 20 min
- Expérimentation : 15 min
- Marge : 12 min pour le dépannage

Préparation :
- Tester tous les boutons avant la séance
- Avoir les deux circuits prêts, un avec résistance de rappel et un sans

*Fin de la leçon 3*
