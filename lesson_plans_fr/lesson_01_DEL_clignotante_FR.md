# Leçon 1 : DEL clignotante

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Aucun. Il s’agit de la première leçon.

## Aperçu

L’objectif de cette leçon est de permettre aux élèves de manipuler les composants, soit physiquement, soit dans leur version virtuelle sur Tinkercad. À la fin de la séance, tous les élèves devraient être capables d’allumer leur DEL et de comprendre en partie le fonctionnement du circuit.

## Objectifs d’apprentissage

Les élèves apprendront :
- Les principales pièces de la trousse Arduino
- Les règles de base de la sécurité électrique
- Comment monter un circuit avec une DEL sur une plaque d’essai ou dans Tinkercad
- Comment téléverser et tester du code sur une carte Arduino ou lancer une simulation
- Comment modifier le code pour changer le rythme de clignotement de la DEL

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 1 DEL (n’importe quelle couleur)
- 1 résistance de 220 Ω (bandes rouge-rouge-brun)
- 2 fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad

### La physique (gardons ça simple)

Petite note sur la loi d’Ohm : V = I × R.

L’Arduino fournit 5 V, mais notre DEL n’a besoin que d’environ 2 V. La résistance sert à absorber les 3 V restants pour éviter que la DEL ne grille.

Rappelez-leur : sans la résistance, le matériel ne durerait pas cinq minutes!

## Avant la leçon

Pour le montage physique :
- Vérifier que toutes les DEL fonctionnent.
- S'assurer que le logiciel Arduino IDE est installé sur tous les ordinateurs.
- Avoir des pièces de rechange (DEL, fils) à portée de main.
- Avoir un circuit d’exemple prêt à montrer.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Vérifier que tous les élèves ont créé leur compte Tinkercad.
- S'assurer que Tinkercad se charge correctement sur tous les ordinateurs.
- Avoir un circuit d’exemple prêt à montrer.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

L’enseignant laisse un élève remplacer delay(1000) par delay(50).

## Déroulement de la leçon

### Ouverture (5 minutes)

Montrez un exemple fonctionnel (physique ou projeté sur Tinkercad).

Expliquez :
- Ce qu’est un Arduino et à quoi ça sert.
- Les composants que nous utiliserons aujourd’hui.
- Répondez aux premières questions.

### Sécurité et préparation (5 minutes)

Quatre règles de sécurité :
1. Suivre les consignes à la lettre : ne pas brancher des composants au hasard.
2. Débrancher immédiatement si une odeur suspecte ou de brûlé se dégage.
3. Ne PAS alimenter le circuit avant qu’il ait été vérifié.
4. Poser des questions : aucune question n’est stupide.

Vérification des composants :
Demandez aux élèves de lever chaque pièce pour confirmer qu’ils ont tout :
- Carte Arduino
- Plaque d’essai
- DEL
- Résistance
- Fils de connexion

### Comprendre la DEL (8 minutes)

Expliquez le fonctionnement de la DEL :
- DEL = diode électroluminescente
- Patte longue (anode) = positive (+), le courant entre
- Patte courte (cathode) = négative (-), le courant sort

Vérification : les élèves identifient la patte longue et la patte courte, ainsi que leur rôle.

### Monter le circuit (25 minutes)

Référence du circuit : voir le guide visuel.

Démontrez chaque étape à l'aide d'un projecteur ou d'une caméra. Les élèves reproduisent le montage. Vérifiez le travail de tout le monde avant de passer à l’étape suivante.

#### Avec des pièces physiques :

Étape 1 : Placer la DEL de part et d’autre de la séparation centrale de la plaque d’essai
- Patte longue dans la rangée 10, côté GAUCHE
- Patte courte dans la rangée 10, côté DROIT

Étape 2 : Connecter la résistance
- Une patte reliée à la patte courte de la DEL (rangée 10, droite)
- L’autre patte reliée au rail de masse (ligne bleue ou marquée du symbole « - »)

Étape 3 : Relier la DEL à la broche 13
- Fil de connexion rouge de la patte longue de la DEL à la broche 13 de l’Arduino

Étape 4 : Relier la masse
- Fil de connexion noir du rail de masse à la broche GND de l’Arduino

Étape 5 : Brancher le câble USB
- Vérifier tous les circuits d’abord.
- Ensuite, brancher le câble USB de l’Arduino à l’ordinateur.

#### En version virtuelle (Tinkercad) :

Étape 1 : Créer un nouveau circuit et le nommer « Leçon 1 — DEL clignotante ».

Étape 2 : Ajouter les composants
- Arduino Uno R3
- Plaque d’essai
- DEL
- Résistance (220 Ω)

Étape 2 b : Régler la valeur de la résistance
- Cliquer sur la résistance.
- Dans le panneau des propriétés, régler la valeur à 220 Ω (ohm).

Étape 3 : Relier les éléments
- Anode de la DEL : plaque d’essai, rangée 10, gauche
- Cathode de la DEL : plaque d’essai, rangée 10, droite
- Résistance : une extrémité à la rangée de la cathode, l’autre au rail de masse
- Fil de connexion : rangée de l'anode de la DEL à la broche 13 de l'Arduino
- Fil de connexion : rail de masse à la broche GND de l'Arduino

Étape 4 : Cliquer sur « Code », puis choisir « Texte ».

### La logique : setup ou loop

void setup() : s’exécute une seule fois au démarrage (lorsqu'on branche la carte). C’est comme la « liste de vérification avant le vol » d’un pilote. On indique à l’Arduino que la broche 13 est une SORTIE (OUTPUT).

void loop() : s’exécute en boucle continue. C’est le « cerveau » du robot qui répète les instructions jusqu’à ce qu’on coupe le courant.

### Écrire le code ensemble (20 minutes)

Référence du code : voir code_examples/lesson_01_blink/

Faites taper UNE ligne à la fois. Vérifiez l’écran de chaque élève après chaque ligne.

```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

Surveillez les erreurs fréquentes :
- Points-virgules (;) manquants
- Majuscules ou minuscules mal utilisées
- Accolades ({ }) manquantes

### Téléverser et tester (10 minutes)

#### Arduino physique :
1. Aller dans Outils > Type de carte > Arduino Uno.
2. Aller dans Outils > Port et choisir « Arduino » ou « USB ».
3. Cliquer sur le bouton Téléverser (flèche).
4. Attendre le message « Téléversement terminé ».

La DEL devrait s’allumer et s’éteindre chaque seconde.

#### Tinkercad :
1. Cliquer sur « Démarrer la simulation ».
2. La DEL devrait clignoter.

Célébrez chaque circuit qui fonctionne!

### Expliquer le code (10 minutes)

Passez le code en revue ligne par ligne :

- `void setup()` : s’exécute une fois au démarrage
- `pinMode(13, OUTPUT)` : la broche 13 contrôle la DEL
- `void loop()` : s’exécute en boucle continue
- `digitalWrite(13, HIGH)` : allume la DEL
- `delay(1000)` : attend 1 seconde (1000 millisecondes)
- `digitalWrite(13, LOW)` : éteint la DEL
- `delay(1000)` : attend 1 seconde, puis recommence

Concept clé : le code est une suite d’instructions que l’Arduino suit exactement, en boucle continue.

### Temps d’expérimentation (12 minutes)

Défis :

1. Essayez de remplacer les deux 1000 par 100. Que se passe-t-il?
2. Essayez de remplacer le premier 1000 par 2000. Que se passe-t-il?
3. (Facultatif) Essayez de faire clignoter la DEL 3 fois rapidement, de faire une pause, puis de recommencer.

Apprentissage clé : changer les nombres change le comportement.

### Clôture (5 minutes)

Questions de révision :
- Que fait digitalWrite(13, HIGH)?
- Que fait delay(1000)?
- Quelle est la différence entre setup et loop?

Aperçu de la semaine prochaine : les motifs de DEL (rapide, lent, rapide). Vous créerez votre propre motif, comme du code morse.

Rangement :
- Débrancher le câble USB
- Garder les circuits montés (ou les démonter avec soin)

## Évaluation

Pendant la leçon :
- Les élèves peuvent-ils identifier les pattes de la DEL?
- Le circuit est-il bien monté?
- La DEL clignote-t-elle?
- Peuvent-ils expliquer les changements après avoir modifié les valeurs de delay?

Billet de sortie :
1. Une chose que tu as apprise aujourd’hui.
2. Une question qui te reste.
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves ont une DEL clignotante qui fonctionne.

## Problèmes fréquents

### La DEL ne s’allume pas

Montage physique :
- DEL à l’envers? (patte longue vers la broche 13)
- Résistance reliée à la masse?
- Fils de connexion bien enfoncés?
- Essayer une autre DEL
- Câble USB branché?

Tinkercad :
- Vérifier les connexions
- Anode et cathode de la DEL au bon endroit?
- Relancer la simulation

### Erreurs de compilation

- Fautes de frappe? (le code est sensible à la casse)
- Points-virgules manquants?
- Accolades bien appariées?

### Impossible de téléverser

- Mauvais port?
- Câble USB mal branché?
- Mauvaise carte sélectionnée?
- Essayer un autre port USB

### Le code se téléverse, mais la DEL ne clignote pas

- Broche 13 dans le code?
- Remonter le circuit
- La DEL intégrée à la carte clignote-t-elle? (Si oui, le problème vient du circuit.)

## Autres situations

Besoin de soutien :
- Monter le circuit à côté de l’élève, étape par étape, au lieu de faire la démonstration à l’avant
- Les faire travailler en équipes de deux : un élève branche les fils pendant que l’autre vérifie le schéma
- Faire d’abord allumer la DEL, et garder l’explication du code pour après

Avancé :
- Peuvent-ils faire clignoter la DEL selon un motif plutôt qu’à intervalles réguliers, par exemple deux clignotements rapides puis une pause?
- Quelle est la plus petite valeur de delay pour laquelle le clignotement ressemble encore à un clignotement plutôt qu’à une faible lueur?
- Peuvent-ils utiliser en même temps la DEL intégrée de la broche 13 et la DEL de leur plaque d’essai?

## Notes pour l’enseignant

Durée :
- Le montage prend de 25 à 30 min
- Prévoir de 10 à 15 min de marge pour le dépannage

Préparation :
- Tester tout le matériel avant le début de la séance
- S’assurer que le logiciel Arduino IDE ou Tinkercad est accessible sur chaque ordinateur
- Avoir un exemple Tinkercad ou physique prêt

*Fin de la leçon 1*
