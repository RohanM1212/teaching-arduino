# Leçon 2 : Motifs de DEL + circuits en série et en parallèle

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçon 1 (DEL clignotante). Les élèves doivent avoir un circuit fonctionnel avec une DEL.

## Aperçu

À la dernière leçon, nous avons fait clignoter une DEL. Dans cette leçon, nous en ajoutons d’autres et nous découvrons que la façon de les brancher change complètement leur comportement.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment fonctionne un circuit en série et pourquoi les DEL y brillent moins
- Comment fonctionne un circuit en parallèle et pourquoi chaque DEL a besoin de sa propre résistance
- Comment contrôler plusieurs DEL avec plusieurs appels à pinMode et à digitalWrite
- Comment écrire un motif de DEL réfléchi, et non choisi au hasard

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- 3 DEL (de couleurs différentes si possible; la différence de luminosité est plus évidente)
- 3 résistances de 220 Ω
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad

### La physique (gardons ça simple)

L’Arduino fournit 5 V. Une DEL rouge a besoin d’au moins 1,8 V environ pour s’allumer.

En série, les DEL se partagent ces 5 V, donc chacune en reçoit moins. En parallèle, chaque DEL reçoit les 5 V au complet.

C’est pourquoi les mêmes composants, branchés différemment, n’ont pas du tout le même résultat.

## Avant la leçon

Pour le montage physique :
- Monter à l’avance un circuit en série (2 DEL) et un circuit en parallèle (2 DEL), et les avoir prêts à montrer côte à côte.
- Avoir le code de clignotement de la leçon 1 prêt pour la partie sur le circuit en série.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir les deux circuits montés à l’avance dans Tinkercad.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

### Moment d’apprentissage

Quand les élèves voient le circuit en parallèle pour la première fois, demandez-leur pourquoi il est plus brillant avant d’expliquer quoi que ce soit.

## Déroulement de la leçon

### Ouverture (5 minutes)

Montrez les deux circuits déjà montés, alimentés en même temps. N’expliquez rien pour l’instant. Laissez-les simplement observer.

Demandez : « Ces deux circuits ont deux DEL et la même source d’alimentation. Pourquoi l’un est-il plus brillant? »

Laissez-les deviner. Ne confirmez rien tout de suite. Dites-leur qu’ils comprendront pourquoi d’ici la fin de la leçon.

### Révision de la leçon 1 (5 minutes)

Petite vérification avant de continuer :
- Que fait void setup()?
- Que fait void loop()?
- Que signifie delay(1000)?

Si la plupart des élèves s’en souviennent, passez à la suite. Sinon, faites un rappel de 2 minutes avant de continuer. Ne vous attardez pas ici.

### Concept : série ou parallèle (10 minutes)

En série :

Montrez le circuit en série. L’électricité n’a qu’un seul chemin. Les deux DEL se partagent la tension. L’Arduino fournit 5 V. La DEL rouge a une tension directe d’environ 1,8 V, c’est-à-dire le minimum dont elle a besoin pour s’allumer. Dans un circuit en série avec 2 DEL, chaque DEL reçoit à peu près la moitié de la tension disponible. Elles s’allument, mais faiblement. Ajoutez une troisième DEL et chacune en reçoit encore moins. On le voit sur les photos des circuits que j’ai montés. Si une DEL brise, tout le circuit s’éteint. C’est pour la même raison que les vieilles lumières de Noël s’éteignaient au complet quand une seule ampoule grillait.

En parallèle :

Chaque DEL a son propre chemin. Chaque DEL reçoit les 5 V au complet. Elles sont plus brillantes et indépendantes les unes des autres. Si l’une d’elles grille, les autres continuent de fonctionner. C’est ainsi que presque tout est branché dans la vie de tous les jours : votre maison, votre téléphone, à peu près n’importe quel appareil.

Un point à surveiller : si on ajoute trop de DEL en parallèle, l’Arduino essaiera de fournir plus de courant qu’il ne le peut, ce qui peut faire griller un fusible ou causer une surchauffe. Alors, n’exagérez pas avec le nombre de DEL.

### Montage, partie 1 : circuit en série (15 minutes)

Objectif : deux DEL branchées en série, toutes deux contrôlées par la broche 13

Référence du circuit : voir le guide visuel (lesson_02_series_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Placer deux DEL sur la plaque d’essai
- DEL 1 : patte longue dans la rangée 5, côté gauche; patte courte dans la rangée 5, côté droit
- DEL 2 : patte longue dans la rangée 8, côté gauche; patte courte dans la rangée 8, côté droit

Étape 2 : Brancher les DEL en série
- Fil de connexion de la patte courte de la DEL 1 (rangée 5, droite) à la patte longue de la DEL 2 (rangée 8, gauche)

Étape 3 : Connecter la résistance
- Une extrémité reliée à la patte courte de la DEL 2 (rangée 8, droite)
- L’autre extrémité reliée au rail de masse

Étape 4 : Relier la patte longue de la DEL 1 à la broche 13

Étape 5 : Relier le rail de masse à la broche GND de l’Arduino

Étape 6 : Brancher le câble USB

#### En version virtuelle (Tinkercad) :
- Mêmes connexions : relier la cathode de la DEL 1 à l’anode de la DEL 2
- Résistance à la fin, reliée à la masse
- Anode de la DEL 1 reliée à la broche 13

Code : utilisez le code de clignotement de la leçon 1. Les deux DEL clignotent ensemble, puisqu’elles partagent le même chemin.

Demandez aux élèves d’observer la luminosité et de s’en souvenir. Ils s’apprêtent à voir quelque chose de différent.

### Montage, partie 2 : circuit en parallèle (15 minutes)

Objectif : deux DEL branchées en parallèle, chacune sur sa propre broche

Référence du circuit : voir le guide visuel (lesson_02_parallel_circuit.png).

#### Avec des pièces physiques :

Étape 1 : Garder la DEL 1 de l’étape précédente (rangée 5)

Étape 2 : Ajouter la DEL 2 séparément
- Patte longue dans la rangée 8, côté gauche; patte courte dans la rangée 8, côté droit

Étape 3 : Donner à chaque DEL sa propre résistance reliée à la masse (deux résistances au total, une par DEL)

Étape 4 : Relier la patte longue de la DEL 1 à la broche 12, et la patte longue de la DEL 2 à la broche 13

Étape 5 : Relier les deux résistances au rail de masse, puis le rail de masse à la broche GND de l’Arduino

#### En version virtuelle (Tinkercad) :
- Chaque DEL a son propre chemin vers la masse
- Anode de la DEL 1 reliée à la broche 12, anode de la DEL 2 reliée à la broche 13

Posez la même question : quelle est leur luminosité maintenant, comparée à tantôt? Pourquoi?

### Écrire le code ensemble (20 minutes)

Référence du code : voir code_examples/lesson_02_led_patterns/

Faites taper le code ensemble, ligne par ligne :

```cpp
void setup() {
  pinMode(11, OUTPUT);  // DEL 1
  pinMode(12, OUTPUT);  // DEL 2
  pinMode(13, OUTPUT);  // DEL 3
}

void loop() {
  digitalWrite(11, HIGH);
  delay(300);
  digitalWrite(11, LOW);

  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);

  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
}
```

Téléversez et lancez le programme. Passez-le en revue ligne par ligne. Chaque DEL s’allume pendant 300 ms, puis s’éteint avant que la suivante s’allume.

Ensuite, donnez-leur 10 minutes pour écrire leur propre motif. La seule règle : ils doivent pouvoir expliquer pourquoi ils l’ont écrit de cette façon.

Si des élèves bloquent, suggérez :
- Les trois DEL clignotent ensemble rapidement trois fois, puis une pause
- En alternance : la DEL 1 est allumée pendant que la DEL 2 est éteinte, puis on inverse
- Compte à rebours : les trois allumées, puis deux, puis une, puis toutes éteintes

### Présentation (5 minutes)

Interrogez 2 ou 3 élèves :
- Demandez-leur de montrer la ligne de code qui contrôle la DEL 1
- Demandez-leur pourquoi ils ont choisi cette valeur de delay
- Demandez à la classe ce qui arriverait si on changeait ce delay pour 100

### Clôture (5 minutes)

Questions de révision :
- Pourquoi les DEL brillaient-elles moins en série?
- Pourquoi chaque DEL en parallèle a-t-elle besoin de sa propre résistance?
- Lequel utiliseriez-vous pour l’éclairage d’une chambre?

Aperçu de la semaine prochaine : les boutons. Au lieu de simplement regarder le circuit fonctionner, vous pourrez le contrôler vous-mêmes.

Rangement :
- Débrancher le câble USB
- Garder les circuits montés si possible; on ajoute des boutons à la prochaine leçon

## Évaluation

Pendant la leçon :
- L’élève peut-il monter correctement un circuit en parallèle?
- Comprend-il pourquoi le circuit en parallèle est plus brillant?
- A-t-il écrit un motif qu’il peut expliquer?

Billet de sortie :
1. Dessine un circuit en série et un circuit en parallèle (un croquis suffit, montre seulement le principe).
2. Une chose qui t’a surpris aujourd’hui.
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : 90 % ou plus des élèves ont un circuit en parallèle fonctionnel et un motif qu’ils peuvent expliquer.

## Problèmes fréquents

### Les DEL ne s’allument pas en série
- Vérifier l’orientation des DEL : elles doivent toutes deux être dans le même sens
- Vérifier le fil entre la cathode de la DEL 1 et l’anode de la DEL 2 (facile à oublier)
- Les circuits en série tolèrent moins bien les mauvais contacts que les circuits en parallèle

### En parallèle, une DEL fonctionne, mais pas l’autre
- Chaque DEL a besoin de sa propre résistance : vérifier que les deux sont là
- Tester séparément la connexion de chaque DEL à sa broche
- Remplacer la DEL qui ne fonctionne pas pour éliminer un composant défectueux

### Le code fonctionne, mais ce n’est pas la bonne DEL qui clignote
- Vérifier que les numéros de broches dans le code correspondent au montage
- Il est plus simple de déplacer le fil sur la plaque d’essai pour qu’il corresponde au code que de réécrire le code

### Des élèves finissent en avance
- Peuvent-ils faire épeler une lettre en code morse par le motif?
- Peuvent-ils imiter un battement de cœur : rapide, rapide, pause?
- Peuvent-ils ajouter une quatrième DEL?

## Autres situations

Besoin de soutien :
- Dessiner le circuit en parallèle à l’avance et le leur faire reproduire
- Les faire travailler en équipes de deux pour le montage
- Faire d’abord fonctionner le circuit, et garder le motif pour après

Avancé :
- Que se passe-t-il avec delay(0)?
- Peuvent-ils faire clignoter deux DEL à des vitesses différentes?
- Que se passerait-il s’ils branchaient 10 DEL en série?

## Notes pour l’enseignant

Durée :
- Montage en série : 15 min
- Montage en parallèle : 15 min
- Programmation du motif : 20 min
- Marge : 10 min pour le dépannage

Préparation :
- Monter et tester les deux circuits avant la séance
- Avoir un exemple Tinkercad ou physique prêt

*Fin de la leçon 2*
