/*
File: CS 125: Programming Project-Choose Your Own Adventure
Authors: Daniel Klucsaris, Rajeev Mandalam, & Luke Overfelt
Version: 1.0.0
Resources: https://github.com/KLUCSARD/CPROJECT, https://stackoverflow.com/questions/14546018/using-scanf-function-with-pointers-to-character, PowerPoint Slides, and Coggle
Date Published: April 8th, 2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Beginning Function
void beginning();

//Functions relating to multiplayer game
void modelH();

//Functions relating to single player game
void singleH();

//Locations
void warehouse();
void nighttime();

//Functions relating to your apartment
void home();
void christopher();

//Ending Functions
void goodEnding();
void death();
void caught();
void decentEnding();

void death() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    printf("You are now dead. Thank you for playing.\n");
    printf("If you would like to see a list of the decisions you made that led you to this point, please type 'CYOADecisions.txt' into your document search bar.\n");
    printf("Goodbye. Better luck next time.\n"); 
    fprintf(file, "You died.\n");
    fclose(file); }
    
void goodEnding() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    fprintf(file, "Congratulations. You found the one good ending. You and Sara live happily ever after and your photos are bought at the gallery.\n");
    printf("Sara arrives about 45 minutes later with a basket and a blanket. The two of you sit down and enjoy a nice dinner.\n");
    printf("As the sun starts to set, you look over and notice how absolutely breathtaking Sara looks today.\n");
    printf("At this point, you tell her that you need to go get something from your car.\n");
    printf("You run back to your car and check your glove compartment. You grab the ring you have been holding onto and decide this is the time.\n");
    printf("You walk back quietly and set your camera up to take a picture. You quietly adjust the settings to make the shot a perfect silhouette shot.\n");
    printf("You set a timer to start taking continuous shots and keep the button to the camera in your pocket so you can control it.");
    printf("You walk back over, get down on one knee and propose to Sara. She says yes and rushes in for a hug and kiss.\n");
    printf("The photo of you proposing and kissing is perfectly captured.\n");
    printf("You submit this photo to the gallery and it sells almost immediately.");
    printf("Congratulations. You managed to beat the game. Good job.\n"); 
    printf("If you would like to see a list of the decisions you made that led you to this point, please type 'CYOADecisions.txt' into your document search bar.\n");
    fclose(file); }

void caught() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    fprintf(file, "You were caught. Game over.\n");
    printf("You were caught by the police. Game over.\n");
    printf("If you would like to see a list of the decisions you made that led you to this point, please type 'CYOADecisions.txt' into your document search bar.\n");
    fclose(file);  
}

void decentEnding() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    fprintf(file, "You go home and your pictures sell at the gallery. Congratulations. You got the decent ending.\n");
    printf("Upon leaving the warehouse, you go back home to Sara and have a nice dinner.\n");
    printf("One of your photos sells at the gallery and you make rent.\n");
    printf("If you would like to see a list of the decisions you made that led you to this point, please type 'CYOADecisions.txt' into your document search bar.\n");
    fclose(file); }


int main() {

    //Opening a file to place the users decisions into
    FILE *file;
    file = fopen("CYOADecisions.txt", "w");
    fprintf(file, "Here's the complete list of decisions that you made along your adventure:\n");
    fclose(file);

    //Variables for decisions
    char begin_game;
    
    //Introduction to the game
    printf("\n\nThe following is a choose-your-own-adventure game.\n");
    printf("The possibilities are endless.\n\n");
    printf("A few notes before we start:\n");
    printf("    1. Anytime a question is asked, a valid answer must be given or I will choose for you\n");
    printf("        1a. This means you MUST enter your choice exactly as we dictate. Don't deviate and do a capital letter instead.\n");
    printf("        1b. To test how well you are paying attention, we will change up the answering style every once in a while.\n");
    printf("    2. You cannot go back, make sure the decision you make is what you want because it might not be available later\n");
    printf("    3. There are no savepoints. If your character dies, you either restart or stop playing\n\n\n");
    printf("	Are you ready to play the game? (Enter 'Y' or 'N'): ");
    scanf(" %c", &begin_game);
    if (begin_game != 'Y' || begin_game == 'N') {
    	printf("Incorrect Response!\n");
        printf("Since this is your first choice of the game, I will give you a second chance to enter a valid response to the question.\n");
        printf("You will not get one of these again for the rest of the game.");
	printf("ARE YOU READY TO PLAY THE GAME?: ");
	scanf(" %c", &begin_game); 
	if (begin_game != 'Y') {
		    death(); }  
    	else {
		beginning(); } }
    else {
	beginning(); }
    return 0; }
	
void beginning() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    int risk, partner;
    
    //Explaining the plot and giving the user their first decision
    printf("\n\nYou are an amateur photographer who has recently found the perfect location for a shoot.\n");
    printf("Unfortunately, the location is frequented by police and you do not have a permit to shoot there.\n");
    printf("Right now you are late on rent by a week and there is an art gallery coming up soon.\n");
    printf("The pictures taken at this location will be perfect for the gallery and means you will have money for rent.\n");
    printf("\nWill you take the risk or just hope that things work out (1 = take the risk; 0 = hope things work out)? ");
    scanf(" %d", &risk);

    //Nested if/else statement that moves the story depending on what the user entered
    if (risk == 1) {
        fprintf(file, "You chose to risk it and go for the photoshoot.\n");
        printf("\n\nFor the shoot, would you like to have a model there with you? Or do you want to work alone? (1 = partner; 0 = alone):");
        scanf(" %d", &partner); 
            if (partner == 1) {
                printf("\nThe models name is Anya.\n");
                printf("She has very little experience in the modeling industry, but she is cheap and her schedule works best with yours.\n");
                fprintf(file, "You chose to shoot with a model.\n");
                modelH(); }
            else if (partner == 0) {
                fprintf(file, "You chose to shoot on your own.\n");
                singleH(); }
            else {
                printf("\n\n\nYou receive a text message from your friend.\n");
                printf("She says that the previous model you worked with talked about your improfessional behavior to everyone\n");
                printf("No models want to work with you even though the model is lying.");
                fprintf(file, "You didn't follow the instructions. We chose to let you shoot alone.\n");
                singleH(); } }
    else if (risk == 0) {
        printf("\n\n\nYou head back to your apartment.");
        fprintf(file, "You chose to not take the risk.\n");
        home(); }
    else {
        printf("\n\n\nYour girlfriend, Sara, sends you a text message.\n");
        printf("She states that the landlord, Christopher, is at your door yelling for rent.\n");
        printf("He states that if he doesn't have his money by the end of the day, he is evicting you.\n");
        printf("Sara tells you to get money no matter what. You are doing the shoot. No models are available so you must do it alone.\n");
        fprintf(file, "You didn't follow instructions. We chose to make you go on the shoot alone.\n");
        singleH(); } }

void modelH() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    float cheat;
    
    printf("\n\n\nYou and Anya set out to the location of the shoot.\n");
    printf("Once you arrive, it seems rather desolate. No cops are around as of now. It's the perfect time to start shooting.\n");
    printf("You exit your car and start setting up your camera to take a few test shots.\n");
    printf("\nAs you do this, Anya comes over to you and attempts to kiss you. Do you cheat on your girlfriend with Anya? (1.69=yes; 0.069=no):");
    scanf(" %f", &cheat);

    if (cheat == 1.69f) {
        fprintf(file, "You cheat on your girlfriend.\n");
        printf("\n\nYou allow Anya to start kissing you. In fact, you kiss her back.\n");
        printf("You start to think of Sara. Just as you start to think of her, your phone rings.\n");
        printf("She knows that you are at a shoot, if you don't pick up she will be mad. You shush Anya and pick up the phone.\n");
        printf("Sara says the following:\n");
        printf("    'Hey, I am on my way home from work and I wanted to know if I should stop for anything. I know you're at a shoot now, but I can stop by.'\n");
        printf("As Sara finishes her sentence, Anya coughs. You stare at her in anger. She mouths an apology.\n");
        printf("Sara heard this and knew what was happening.\n");
        printf("    'Are you kidding me? Are you serious? You're really doing this to me again?!'\n");
        printf("You try to explain yourself, but she interrupts you.\n");
        printf("    'Don't bother. Go have dinner with whoever it is this time.'\n");
        printf("At this, Sara hangs up the phone.\n"); 
        printf("You and Anya get out of the car and start shooting.\n");
        printf("Around twenty minutes after you start shooting, you hear the sound of tires screeching.\n");
        printf("As you turn around, a force pushes your body forward.\n");
        printf("Just before the life leaves your body you have a realization that it must be Sara, murdering both you and Anya as revenge.\n"); 
        death(); }
    else if (cheat == 0.069f) {
        printf("\n\nYou push Anya away and tell her that you're not doing that anymore.");
        printf("The shoot becomes awkward from there and Anya leaves.\n");
        singleH();
        fprintf(file, "You didn't cheat on your girlfriend.\n"); }
    else {
        printf("\n\nYou allow Anya to kiss you, but you don't kiss her back.");
        printf("After about a minute of this, she gets upset. She wants to know why you aren't kissing her back.\n");
        printf("She starts crying, thinking that you don't find her attractive anymore. She's clearly being overdramatic to make you feel bad.\n");
        printf("You don't give into her overdramatic antics and she becomes even more upset.\n");
        printf("She slaps you across the face, exerting a tremenduous amount of force.\n");
        printf("You're pretty sure she broke your jaw, but, just like before, you don't do anything.");
        printf("She continues beating on you until you are on the ground, crying. She grabs your camera and throws it across the street.\n");
        printf("Finally, you get up and do something.\n");
        printf("You run after your camera, neglecting to look in the street.\n");
        printf("Just as you pick the camera up, an 18-wheeler smashes into you, killing you on the spot.\n");
        fprintf(file, "You cheat on your girlfriend.\n");
        death(); }
 }

void singleH() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    int combination;
    char yesorno[10];
    
    printf("\n\nYou pick up your camera, noticing how beautiful the sunlight reflects off the glass is.\n");
    printf("You start to take photos of the warehouse and the surroundings.\n");
    printf("After getting around 100 photos (20 of which were probably salvageable).\n");
    printf("After a few more minutes of shooting, you get a phone call.\n");
    printf("It is Sara, do you answer (yes or no)?");
    scanf(" %s", yesorno);
    
    if (strcmp(yesorno, "yes") == 0) {
        fprintf(file, "You chose to answer the phone.\n");
        printf("\nSara says that she really appreciates the fact that you are working so hard to provide for her.\n");
        printf("She says that she wants to surprise you at work and maybe have a picnic at the location.\n");
        printf("You tell her that you will be working for a while, but you would love it if she stopped by.\n");
        goodEnding(); }
    else if (strcmp(yesorno, "no") == 0) {
        fprintf(file, "You chose to ignore Sara's call.\n");
        printf("\nSara leaves you a voicemail. Do you want to listen to it right now (yes or no)?");
        scanf(" %s", yesorno);
            if (strcmp(yesorno, "yes") == 0) {
                fprintf(file, "You listened to the voicemail.\n");
                printf("\nThe message is Sara explaining that she wanted to stop by for a picnic at the warehouse.\n");
                printf("However, she says that she assumes you are too busy with work to answer so she will just have dinner ready when you get back.\n");
	  	printf("\nSuddenly, you see police coming up over the hill. You run to the warehouse entrance and try to get in. There is a padlock on it.\n");
    		printf("On the padlock, the numbers 8, 32, 9, and 4 are scratched out. You assume that this must be the combination.\n");
    		printf("\nYou start turning the dial to different combinations. Enter the numbers in the order you think they are. Do not space them out. Enter it as one number: ");
    		scanf(" %d", &combination);
    
    		if (combination == 93248) {
        		printf("\nCongratulations, you guessed the combination. You now enter the warehouse.\n"); 
        		fprintf(file, "You enter the warehouse.\n");
        		warehouse(); }
    		else if (combination != 93248) {
        		while (combination != 93248) {
        			printf("\nThe combination you entered was incorrect. Try again: ");
        			scanf(" %d", &combination); } 
        			fprintf(file, "You enter the warehouse.\n");
        			warehouse(); }
    		else {
        		printf("\nThe numbers you entered were invalid. The police catch you and you go to jail.");
        		caught(); }  }
             else if (strcmp(yesorno, "no") == 0) {
                fprintf(file, "You chose not to listen to Sara's voicemail.\n");
		printf("\nSuddenly, you see police coming up over the hill. You run to the warehouse entrance and try to get in. There is a padlock on it.\n");
    		printf("On the padlock, the numbers 8, 32, 9, and 4 are scratched out. You assume that this must be the combination.\n");
    		printf("You start turning the dial to different combinations. Enter the numbers in the order you think they are. Do not space them out. Enter it as one number: ");
    		scanf(" %d", &combination);
    
    		if (combination == 93248) {
        		printf("\nCongratulations, you guessed the combination. You now enter the warehouse.\n"); 
        		fprintf(file, "You enter the warehouse.\n");
        		warehouse(); }
    		else if (combination != 93248) {
        		while (combination != 93248) {
        			printf("\nThe combination you entered was incorrect. Try again: ");
        			scanf("%d", &combination); } 
        			fprintf(file, "You enter the warehouse.\n");
        			warehouse(); }
    		else {
        		printf("\nThe numbers you entered were invalid. The police catch you and you go to jail.");
        		caught(); } } 
            else {
                fprintf(file, "You didn't follow instructions. That got you killed.\n");
                printf("\nYou reach for your phone, but as you grab hold of it a loud noise shatters the silence.\n");
                printf("You fall to the ground, feeling the metal move inside of you as you fall.\n");
                printf("You are staring up at the sky when you see a figure step over you.\n");
                printf("They point a gun at your face and say, 'I think we should see other people.' as she pulls the trigger.\n");
                death(); } }
    else {
        fprintf(file, "You didn't follow instructions. That got you killed.\n");
        printf("\nYou answer the phone and hear a man on the other line say, 'Don't move' before a loud blast shatters the silence.\n");
        printf("The hitman's bullet goes straight through your head and you fall to the ground wondering how he was able to get it to display Sara's contact information.\n");
        death(); }      
}

void home() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    char yOrN;
    
    fprintf(file, "You chose to go home.\n");
    printf("\n\n\nBack at your apartment you rest on the couch.\n");
    printf("You are searching through your laptop for pictures that could go in the gallery.\n");
    printf("While searching, you notice a picture of your girlfriend taken a while back.\n");
    printf("This photo was taken on your 1 year anniversary.\n");
    printf("In the picture, she can be seen facing away from the camera on a bridge.\n");
    printf("The sun is setting at the time, making the photo an almost pseudo-silhoutte style.\n");
    printf("The colors in the sky are shining off of her red hair that is dancing in the wind.\n");
    printf("The picture does not have much special in it. It is nothing new, but it is a good shot.\n");
    printf("\nShould you try submitting this to the art gallery? (y = yes; n = no): ");
    scanf(" %c", &yOrN); 

    if (yOrN == 'y') {
        fprintf(file, "You chose to use the photos you already had.\n");
        printf("\n\nYou send the photo into PhotoShop to do some work on it to make it gallery ready.\n"); }
    else if (yOrN == 'n') {
        fprintf(file, "You chose not to use the photos you had.\n");
        printf("\n\nYou close your laptop, feeling defeated and questioning your talent in the field.\n");
        printf("As you do this, you hear keys rattling in the door.\n");
        printf("You quickly open up your laptop to appear as though you are doing work\n");
        printf("Sara walks into the room and gives you a smile.\n");
        printf("She asks if you have decided if you will shoot at the location or not.\n");
        printf("\nDo you tell her (y = yes; n = no)?");
        scanf(" %c", &yOrN); 
        
        //Nested if-else statement
        if (yOrN == 'y') {
            fprintf(file, "You did tell Sara that you did not choose to shoot.\n");
            printf("\n\nSara becomes irritated and passive aggressive about it.\n");
            printf("She scoffs at you, you get up and follow her into the kitchen.\n");
            printf("Placing your arms around her waist, you attempt to kiss her, but she pushes you away.\n");
            printf("Do you ask her what's wrong (y = yes; n = no)?");
            scanf(" %c", &yOrN);
        
            //Nested if-else statement in a nested if-else
            if (yOrN == 'y') {
                fprintf(file, "You asked Sara what is wrong.\n");
                printf("\n\nSara spins around at you and raises her voice. She says the following: \n");
                printf("    'Nothing is wrong. Nothing at all. Except for the fact that I have apparently'\n");
                printf("    'been wasting the last year and a half of my life with someone who doesn't care about me'\n");
                printf("You attempt to interject, but she cuts you off.\n");
                printf("    'I thought that photography was all about risk. Taking a big risk for the shot.'\n");
                printf("    'No wonder you are an amateur. You don't even have the guts to go for a photoshoot.'\n");
                printf("    'That's all you're ever going to be is an amateur.'\n");
                printf("At this, she reveals that she has been cheating on you for the past month and that she doesn't love you anymore.\n");
                printf("She says that she is unhappy and doesn't want to be with you anymore.\n"); }
            else if (yOrN == 'n') {
                fprintf(file, "You did not ask Sara what is wrong.\n");
                printf("\n\nSara spins around and says the following: \n");
                printf("    'Typical. I don't know why I would have expected you to have the guts to confront me.'\n");
                printf("    'Especially when you can't even take a picture! You're worthless and pathetic.'\n");
                printf("Sara walks out the door after this, leaving you in the apartment all alone.\n");
                christopher(); }
            else {
                fprintf(file, "You did not follow instructions. Sara yells at you.\n");
                printf("\n\nSara screams at you to stop being so passive. She breaks down saying how much you have made her hate her life.\n");
                printf("That she dreads coming home to you everyday because you can never give her a straight answer.\n");
                printf("She says that she has been cheating on you for the past year and breaks up with you."); } }

        else if(yOrN == 'n') {
            fprintf(file, "You lie to Sara.\n");
            printf("\n\nSara says the following: \n");
            printf("    'You're a bad liar, you know?'\n");
            printf("    'Never once in this entire relationship have you gotten away with lying, so why try now?'\n");
            printf("    'You're so transparant that it's actually sad. You will never be able to get away with lying.'\n");
            printf("    'I saw right through you when you said you didn't sleep with that model you were shooting.'\n");
            printf("    'If you're going to lie to me you should at least be good at it.'\n");
            printf("\nAfter this, Sara walks out and slams the door behind her.");
            printf("A picture of the two of you together falls to the ground and breaks the frame.\n");

            christopher(); }

        else {
            fprintf(file, "You did not follow instructions.");
            printf("\n\nSara stabs you. You die.\n"); 
            death();} }
    else {
        fprintf(file, "You did not follow instructions.\n");
        printf("\n\n\nYour computer explodes. The shrapnel impales you and you die.\n"); 
        death(); } }

void christopher() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    char door;

    printf("\n\n\nYour landlord, Christopher, starts banging on your door and yells at you for rent.\n");
    printf("He says that this is the last time he will ever accept a late payment and that next time he will evict you.\n");
    printf("He says he knows you are in there and asks you to open up.\n");
    printf("\nDo you open the door (y = yes; n = no)?");
    scanf(" %c", &door);

    if (door == 'y') {
        fprintf(file, "You opened the door when Christopher knocked.\n");
        printf("\nYou open the door, looking distraught and he yells at you for the money.\n");
        printf("You say you don't have it, but he says that if he doesn't get paid by the end of the week (when the art gallery is) he will evict you.\n");
        printf("You say okay and promise to have his money by then.\n"); 
        nighttime(); }
    else if (door == 'n') {
        fprintf(file, "You did not open the door to Christopher.\n");
        printf("\nHe yells that if he doesn't get his money by the end of the week, he is evicting you.\n"); 
        nighttime(); }
    else {
        fprintf(file, "You did not follow instructions. Christopher evicts you.\n");
        printf("\nHe yells that you are being evicted and that you have an hour to get off the premises.\n");
        printf("He walks away after this.\n"); 
        nighttime(); }
}

void nighttime() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");

    int bar_or_sleep, drink_again, take_shot=1, number_of_shots=1, drive_or_walk;  
    char your_drink[20];
    printf("\n\nDistraught about the revelations regarding Sara's infidelity, and having no way to pay Christopher, you decide that you need to take your mind off of things.\n");
    printf("\nHow do you approach the situation? Will you go to bed, or go to the bar to get a few drinks? (1 = go to bed, 0 = go to bar)\n");

    if (bar_or_sleep == 1) {
        fprintf(file, "You chose to go to bed.\n");
        printf("\nYou heat up some tea and go to your bed to drink it slowly before going to sleep.\n");
        printf("As you are sipping, you contemplate how you will be able to get the money to Christopher in the next few days.\n");
        printf("You fear the worst-case scenario, with Christopher kicking you out and Sara dumping you.\n");
        printf("You start to shed a tear thinking about Sara, and all of the memories that you have made with her throughout the time you both have been together.\n");
        printf("All of those times you both had stability, comfort, and fun.\n");
		printf("However, all of that could very well be gone in the next 24 hours if you do not accomplish your mission.\n");
        printf("You try to go to sleep after finishing your tea, but a terrible image of your dead body lying in front of your apartment door keeps you awake for a while.\n");
        printf("On the outside, you seem to be cool and collected; but on the inside, fear, anxiety, and panic have completely taken over your soul.\n");
        printf("You eventually fall alseep, but it past midnight by the time you do.\n"); }
    else {
        fprintf(file, "You chose to go to the bar.\n");
        printf("\nYou get in your car and you drive to the nearest bar.\n");
        printf("You are still bothered by the fight you just had with Sara, but you hope that you can wash it off with a few drinks.\n");
        printf("The bartender asks you what you want. What do you choose?\n");
        scanf(" %[^\n]", your_drink);
        printf("\nYou start to sip your %s, and you feel a sense of frustration at the thought of a life without your girlfriend and your apartment. You want this moment to wash away forever. You gradually start to fall into the pit of madness.\n", your_drink);
        for (take_shot==1; take_shot!=0; number_of_shots++) {
            printf("\nDo you want to take another shot (1=yes; 0=no)?");
            scanf(" %d", &take_shot);
            if (number_of_shots >= 15) {
                printf("\nEverybody at the bar notices how intoxicated you are as you yell at the bartender for your 15th shot.\n");
                printf("Your face is full of sweat, you're numb of all senses, and you have completely submerged into a state of insanity.\n");
                printf("The bartender refuses to adheer to your demand, but you keep screaming at him to give it to you.\n");
                printf("Then, the bouncer grabs you by the collar, and throws you out.\n");
                printf("You are on the ground continuing to hallucinate.\n");
                printf("As you lie there, covered in mud and grime, you never would have thought that alcohol poisoning would be the way you go.\n");
                printf("Suddenly, you fall into a deep sleep, and never wake up again. You die.\n");
		death(); }
            else if (number_of_shots >= 5 || number_of_shots < 15) {
	    	printf("\nAs you decide to leave the bar, you are struck with the decision of getting in your car and driving home or walking home.\n");
                printf("You know you had a little more than you should have and driving may not be the best option but it is very late and walking home could be dangerous.\n");
                printf("\nWhat do you do? 1 = car, 0 = walk\n");
                scanf(" %d", &drive_or_walk);
                
                //Nested if-else statement
                if (drive_or_walk == 1) {
                    fprintf(file, "You chose to drive drunk.\n");
                    printf("\nYou get into your car and make the poor choice of driving./n");
                    printf("You make it around the corner and you start thinking of Sara and what you could have said.\n");
                    printf("You suddenly look up and see a tree 10ft ahead.\n");
                    printf("Without enough time to turn out of the way, you crash into the tree and go through the windshield because you forgot to put your seatbelt on.\n");
                    printf("You die.\n"); 
                    death(); }
                else if (drive_or_walk == 0) {
                    fprintf(file, "You chose not to drive drunk.\n");
                    printf("\nYou begin the walk home.\n");
                    printf("While on the way home you contemplate how you could have handled things better with Sara and how you can make things right and move forward.\n");
                    printf("While walking home, you fall into the street in front of an oncoming 18-wheeler.\n"); 
                    death(); }
          printf("You took %d shots.", number_of_shots); } } } } 

void warehouse() {
    FILE *file;
    file = fopen("CYOADecisions.txt", "a");
    
    char yesorno[5];
    
    printf("\nYou enter the warehouse and immediately notice how dark it is. Not only are the windows not letting the light in, but the darkness doesn't seem to be leaving.\n");
    printf("\nShould you use your camera flash for light (YES or NO)?");
    scanf(" %s", yesorno);

    if (strcmp(yesorno, "YES") == 0) {
        fprintf(file, "You use your flash to see in the warehouse.\n");
        printf("\nYou use your flash and see a hideous demon creature launch at you, killing you on the spot.\n");
        death(); }
    else if (strcmp(yesorno, "NO") == 0) {
        fprintf(file, "You do not use your flash to see in the warehouse.\n");
        printf("\nYou decide not to use your flash and just wait for the cop to pass before leaving.");
        decentEnding(); }
    else {
        fprintf(file, "You didn't follow instructions.\n");
        printf("\nYou attempt to use your camera light, but as you lift your camera up a voice whispers, 'No' in your ear.\n");
        printf("The whisper sends shivers down your spine.\n");
        printf("You try to scream, but you are unable to move your mouth.\n");
        printf("You try to run, but arms of this creature wrap around you. Pulling you closer into its simultaneously warm and cold body.\n");
        printf("Darkness surrounds you. Darkness darker than the warehouse. This isn't the absence of light. This is darkness.\n");
        printf("The doesn't kill you, though. He keeps you with him for a while, simply cutting off your senses one by one.\n");
        printf("The first to go was sight. Then hearing, taste, smell and then finally touch.\n");
        printf("Imagine that, losing every sense except your sense of touch, but still not being able to move.\n");
        printf("It was at this point that you realized there is another, unknown sense: fear.\n");
        printf("Your sense of fear was the only thing this creature left, until one day you withered away.\n");
        death(); }
 }
