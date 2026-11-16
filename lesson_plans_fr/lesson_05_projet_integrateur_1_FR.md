# Leçon 5 : Projet intégrateur 1 – Montez votre propre circuit

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçons 1 à 4. Les élèves doivent être à l’aise avec les DEL, les boutons et les potentiomètres.

## Aperçu

Aucune consigne dans cette leçon. Les élèves utilisent tout ce qu’ils ont appris aux leçons 1 à 4 et montent ce qu’ils veulent. Certains feront quelque chose de simple. D’autres vous surprendront. Les deux sont corrects.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment concevoir un circuit à partir de zéro avec ce qu’ils savent déjà
- Comment écrire du code pour un problème qu’ils ont eux-mêmes imaginé
- Comment expliquer chacune de leurs décisions
- Comment dépanner leur propre circuit quand quelque chose ne fonctionne pas

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- Plusieurs DEL (de couleurs différentes si possible)
- Plusieurs résistances de 220 Ω
- 1 bouton-poussoir
- 1 résistance de 10 kΩ (résistance de rappel)
- 1 potentiomètre
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad

### Les exigences (à présenter au début)

- Utiliser au moins 2 composants vus dans les leçons
- Le code doit contenir au moins une instruction if
- Les élèves doivent pouvoir expliquer à quoi sert chaque partie et pourquoi elle est là

### Moment d’apprentissage

Pendant le montage, quand un élève bloque, posez-lui des questions au lieu de régler le problème à sa place. « Qu’est-ce que tu veux que cette partie fasse? » fonctionne mieux que de simplement lui montrer.

## Avant la leçon

Pour le montage physique :
- Trier tous les composants pour que les élèves n’aient pas à chercher les pièces.
- Garder les exemples fonctionnels des leçons 1 à 4 au cas où les élèves auraient besoin d’une référence.
- NE PAS préparer de circuit déjà monté. Il n’y a pas d’exemple à montrer cette fois-ci.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir les leçons 1 à 4 enregistrées dans Tinkercad comme référence.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

## Déroulement de la leçon

### Ouverture (5 minutes)

Annoncez à la classe ce qui se passe aujourd’hui : aucune consigne, aucun circuit à copier. Les élèves montent ce qu’ils veulent avec ce qu’ils savent déjà.

Demandez : « Qu’est-ce que vous auriez voulu faire pendant l’une des quatre dernières leçons, mais qu’on n’a pas eu le temps de faire? »

Laissez quelques élèves répondre. Ça lance les idées avant le remue-méninges.

### Orientation et exigences (15 minutes)

Passez en revue ce qu’ils ont à leur disposition :

Composants qu’ils connaissent :
- DEL
- Bouton-poussoir
- Potentiomètre
- Résistances

Code qu’ils connaissent :
- digitalWrite et digitalRead
- analogRead et analogWrite
- delay
- Instructions if et else
- Variables

Présentez les trois exigences de la section ci-dessus.

Proposez une idée d’exemple sans la monter. Par exemple : « Vous pourriez faire une veilleuse qui s’allume quand on appuie sur un bouton et qui devient plus brillante plus on tourne le potentiomètre. » Précisez tout de suite que ce n’est qu’une idée et qu’ils doivent trouver la leur.

Une règle : ils ne peuvent pas simplement copier le code d’une leçon précédente. Ce doit être quelque chose de nouveau, même si ça utilise les mêmes concepts.

### Remue-méninges (10 minutes)

Avant de toucher à un seul composant, chaque élève écrit 3 idées. Elles n’ont pas besoin d’être bonnes. Seulement 3 choses différentes.

Circulez pendant qu’ils écrivent. Si un élève bloque, demandez-lui :
- « Y a-t-il quelque chose de la vie de tous les jours que tu pourrais simuler avec une DEL et un bouton? »
- « Quelle a été la partie la plus intéressante des quatre dernières leçons? »
- « Qu’est-ce que tu monterais si tu avais plus de composants? »

Après 10 minutes, chaque élève choisit une idée et l’encercle. C’est ce qu’il va monter.

Si deux élèves choisissent la même idée, ce n’est pas grave. Leur code et leur montage finiront par être différents de toute façon.

### Montage (60 minutes)

Les élèves montent leur circuit. Circulez et aidez-les.

Quand un élève bloque, posez-lui des questions au lieu de régler le problème à sa place :
- « Qu’est-ce que tu veux que cette partie fasse? »
- « Qu’est-ce que cette ligne de code dit à l’Arduino? »
- « Qu’est-ce que tu as déjà essayé? »

Intervenez directement seulement si l’élève bloque sur le même problème depuis plus de 5 minutes et que les questions ne l’aident pas.

Élèves qui terminent en avance : demandez-leur d’ajouter une fonctionnalité. Ils ont utilisé un bouton? Peuvent-ils ajouter le potentiomètre? Ils ont deux DEL? Peuvent-ils en ajouter une troisième avec un comportement différent?

Élèves en difficulté : simplifiez avec eux. Demandez-leur à quoi ressemble la version minimale de leur idée. Montez celle-là d’abord, puis ajoutez-y des éléments ensuite.

Élèves qui ont copié une leçon précédente : demandez-leur de changer au moins trois choses pour que le projet devienne le leur.

Quand il reste 10 minutes, dites à la classe d’arrêter d’ajouter des fonctionnalités et de faire fonctionner ce qu’ils ont. Des fils mal branchés et des fonctionnalités à moitié terminées n’aident pas au moment de la démonstration.

### Démonstrations (10 minutes)

Faites le tour de la classe. Chaque élève a 60 secondes pour :
- Montrer son circuit en fonctionnement
- Expliquer une décision qu’il a prise
- Nommer une chose qu’il ajouterait s’il avait plus de temps

N’évaluez pas la complexité. Évaluez si l’élève peut expliquer ce qu’il a monté et pourquoi.

### Clôture (5 minutes)

Demandez à la classe :
- Qu’est-ce qui a été le plus difficile quand vous avez monté un circuit sans consignes?
- Quelqu’un a-t-il réussi quelque chose qu’il ne pensait pas pouvoir faire?
- Quel composant aimeriez-vous avoir?

Aperçu de la semaine prochaine : le servomoteur. Au lieu de DEL qui s’allument et s’éteignent, quelque chose va vraiment bouger.

Rangement :
- Débrancher le câble USB
- Démonter avec soin et remettre les composants dans les bacs

## Évaluation

Pendant la leçon :
- L’élève a-t-il conçu son propre circuit ou copié une leçon précédente?
- Le circuit respecte-t-il les trois exigences?
- L’élève peut-il expliquer son code ligne par ligne?

Billet de sortie :
1. Dessine ton circuit de mémoire.
2. Une chose que tu as trouvée par toi-même aujourd’hui.
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : chaque élève a un circuit fonctionnel qu’il a conçu lui-même et qu’il peut expliquer.

## Problèmes fréquents

### L’élève ne trouve pas d’idée
- Commencer plus petit : lui demander de faire faire à une DEL quelque chose qu’elle n’a fait dans aucune leçon précédente
- S’il bloque complètement, lui donner l’idée de la veilleuse comme point de départ

### L’élève copie exactement une leçon précédente
- Lui demander de changer le comportement d’au moins trois façons
- « Qu’est-ce qui ferait que ce projet est le tien plutôt que le mien? »

### Le circuit fonctionne, mais l’élève ne peut pas l’expliquer
- Passer le code en revue ligne par ligne avec lui
- Lui demander de lire chaque ligne à voix haute et de dire ce qu’elle fait selon lui

### L’élève termine en 20 minutes
- Lui demander ce qu’il ajouterait s’il avait un composant de plus
- Peut-il faire fonctionner son circuit sans le bouton?

## Autres situations

Besoin de soutien :
- Les laisser travailler avec un partenaire
- Leur donner un circuit de départ avec un composant déjà branché et les laisser le compléter

Avancé :
- Pouvez-vous faire en sorte que votre circuit fasse trois choses différentes selon jusqu’où on tourne le potentiomètre?
- Pouvez-vous faire en sorte que le bouton allume et éteigne quelque chose en alternance au lieu de devoir le maintenir enfoncé?

## Notes pour l’enseignant

Le remue-méninges est plus important qu’il en a l’air. Les élèves qui passent directement au montage bloquent généralement plus vite, parce qu’ils n’ont pas réfléchi à ce qu’ils voulaient faire. Tenez bon : 3 idées avant que quiconque touche à un composant.

La démonstration à la fin compte. Même si un circuit fonctionne à peine, présenter son travail donne à chaque élève l’impression d’avoir construit quelque chose de concret. Gardez-la courte, mais ne la sautez pas.

Votre rôle dans cette leçon est différent de celui des autres leçons. Vous n’enseignez pas de nouvelle matière. Vous posez de bonnes questions et vous laissez les élèves travailler.

Durée :
- Ouverture : 5 min
- Orientation et exigences : 15 min
- Remue-méninges : 10 min
- Montage : 60 min
- Démonstrations : 10 min
- Clôture : 5 min
- Aucune marge. Si une partie déborde, prenez le temps sur le montage, et non sur les démonstrations.

Préparation :
- Trier tous les composants avant la séance
- Avoir les leçons 1 à 4 enregistrées et prêtes à consulter

*Fin de la leçon 5*
