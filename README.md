OMAΔIKO PROJECT

Ονοματεπώνυμα:  Ευαγγελία Γούλα  sdi2000040
                Καλλιόπη - Χριστίνα Δεσποτίδου sdi2000045

compile:
     g++ -o run my_main.cpp MODULES/vehicle.cpp MODULES/toll.cpp MODULES/entrance.cpp MODULES/segment.cpp MODULES/attica.cpp                

Καλησπέρα! Θα προσπαθήσουμε να εξηγήσουμε πώς ακριβώς υλοποιήσαμε την Εργασία του μαθήματος για γίνει ο κώδικας κατανοητός. :)

Ας ξεκινήσουμε από τη main...

                                          ---my_main---
--->Η main δέχεται από τη γραμμή εντολών τον αριθμό των κύκλων προσομοίωσης, τον αριθμό των τμημάτων την Αττικής οδού, τον μέγιστο αριθμό οχημάτων που μπορούν να εισέλθουν σε ένα τμήμα του
αυτοκινητοδρόμου από κάποιο διόδιο με εισπράκτορα και το ποσοστό των οχημάτων σ΄ ένα τμήμα που μεταβαίνει σε κατάσταση “ετοιμότητας” για 
έξοδο από το τμήμα στην επόμενη κατάσταση.

---> Στη συνέχεια δημιουργεί μια attica και της περνάει τα κατάλληλα ορίσματα.

---> Καλείται επαναληπτικά η operate της attica για Ν κύκλους προσομοίωσης.


                                        ---class vehicle---
--->Στην κλάση αυτή υπάρχουν 3 private members: ο exit_node είναι ο τελικός κόμβος, δηλαδή ο προορισμός του κάθε οχήματος, το current_segment είναι το
τμήμα που βρίσκεται το όχημα στον κάθε κύκλο προσομοίωσης, το ready αντιπροσωπεύει την κατάσταση ετοιμότητας.

---> Στον constuctor μέσω της μεταβλητής exit περνάμε τον τελικό κόμβο κάθε οχήματος. Αρχικοποιούμε τον current_segment σε -1 και τον ready σε false. 

---> Στην set_current_segment με όρισμα i, ενημερώνουμε κάθε φορά το τμήμα στο οποίο βρίσκεται το όχημα. 

---> Η exit_attica επιστέφει αν είναι έτοιμο το όχημα να βγει από τον αυτοκινητόδρομο ανάλογα με το αν η συνθήκη exit_node==current_segment είναι αληθής ή όχι.

---> Στην set_exit_segment με όρισμα ready ενημερώνουμε την κατάσταση ετοιμότητας του οχήματος.

---> Η get_exit_segment επιστρέφει την κατάσταση ετοιμότητας του οχήματος.


                                        ---class toll---
--->Η κλάση αυτή έχει 3 protected members. Το πρώτο είναι μία queue με οχήματα, το δεύτερο ο αριθμός των οχημάτων που έχουν κάθε στιγμή τα διόδια και το τρίτο είναι το speed, δηλαδή το Κ που 
αντιστοιχεί σε κάθε διόδιο.

---> Στον constuctor δημιουργείται ένας τυχαίος αριθμός οχημάτων. Σε κάθε όχημα περνάται τυχαίος αριθμός που αντιπροσωπεύει τον τελικό κόμβο και ύστερα το όχημα γίνεται push στην queue vehicles.

---> Η μέθοδος get_num_of_vehicles επιστρέφει το num_of_vehicles.

---> Η συνάρτηση get_vehicle επιστρέφει reference στο πρώτο όχημα της queue vehicles.

---> Η συνάρτηση get_speed επιστρέφει την ταχύτητα.

---> Η συνάρτηση set_speed είναι pure virlual καθώς η υλοποίησή της διαφέρει ανάλογα με το αν το διόδιο είναι με εισπράκτορα ή ηλεκτρονικό.

---> Η μέθοδος add αυξάνει τον αρθμό των οχημάτων του διοδίου κάνοντας push στην queue ένα όχημα και η sub αντίστοιχα τα αφαιρεί.

---> Η toll είναι υπερκλάση και έχει δύο υποκλάσεις, την employe_toll και την electronic_toll. 


                                ---classes employe_toll και electronic_toll---
---> Κληρονομούν την κλάση toll. 

---> Οι constructor τους γίνονται μέσω του constructor της υπερκλάσης.

---> Η set_speed ενημερώνει την ταχύτητα με Κ στην employe_toll και με 2Κ στην electronic_toll.


                                        ---class entrance---
--->Η κλάση αυτή έχει 4 private members: το πρώτο είναι ο αριθμός των διοδίων της εισόδου, το δεύτερο είναι ο αριθμός των οχημάτων στην entrance, το τρίτο είναι ο κόμβος της εισόδου, το τέταρτο 
είναι ο δείκτης στην αρχική θέση του πίνακα tolls και το πέμπτο είναι δείκτης στο segment της κάθε εισόδου.

---> Στον constructor δημιουργείται ένας τυχαίος αριθμός διοδίων με εισπράκτορα και ένας τυχαίος αριθμός ηλεκτρονικών διοδίων. Επίσης δημιουργείται ένας πίνακας με num_of_tolls διόδια. Στη 
συνέχεια δημιουργούνται εναλλάξ διόδια με εισπράκτορα και ηλεκτρονικά διόδια.

---> Η μέθοδος get_num_of_vehicles επιστρέφει τον αριθμό των οχημάτων της εισόδου.

---> Η συνάρτηση get_node επιστρέφει το όνομα/ταυτότητα του κόμβου της εισόδου.

---> H συνάρτηση operate με ορίσματα το NSegs και το Κ. Η operate έχει αρχικά έναν counter για τα οχήματα που εισέρχονται στα διόδια (vehicles_to_enter_counter) και 2 μεταβλητές για το όριο των 
οχημάτων που δέχεται το κάθε διόδιο ανάλογα με το αν είναι με εισπράκτορα ή ηλεκτρονικό (employe_tolls_limit και electronic_tolls_limit αντίστοιχα).
ΦΡΟΝΤΙΖΟΥΜΕ ΝΑ ΥΠΑΡΧΟΥΝ ΠΑΝΤΑ ΟΧΗΜΑΤΑ ΣΤΗΝ ΕΙΣΟΔΟ/ΔΙΟΔΙΑ.
Όσο (while)  η χωρητικότητα είναι αρκετή και δεν έχει ξεπεραστεί το όριο και των δύο ειδών διοδίων, περνάνε οχήματα από τα διόδια.
Αυτό γίνεται επαναληπτικά (for loop), ελέγχοντας αν επαρκεί η χωρητικότητα και αν ανάλογα με το είδος του διοδίου, που το ξεχωρίζουμε από την ταχύτητά του, μπορούν να περάσουν κι άλλα οχήματα από τα διόδια (αν 
ακόμη δεν έχει ξεπεραστεί το όριο του διοδίου). Περνάμε στο τέλος του πίνακα του segment το όχημα που εισέρχεται και κάνουμε την κατάσταση ετοιμότητάς του false. Μειώνουμε τη χωρητικότητα κατά 
ένα, αυξάνουμε τα οχήματα του τμήματος κατά ένα, αφαιρούμε το όχημα από το διόδιο, μειώνουμε τα οχήματα της εισόδου κατά ένα και αυξάνουμε τον vehicles_to_enter_counter
(τον μετρητή για το πόσα οήματα εισέρχονται από την είσοδο κάθε φορά), στο τέλος , μειώνουμε το όριο του διοδίου κατά ένα ανάλογα με το είδος του. Στην περίπτωση που η χωρητικότητα δεν επαρκεί, διακόπτουμε την εισαγωγή των οχημάτων στο τμήμα (break).
Αν το όριο των διοδίων με εισπράκτορα και των ηλεκτρονικών διοδίων μηδενίσει, δηλαδή αν περάσουν όλα τα αυτοκίνητα από τα διόδια, τότε αυξάνουμε το Κ κατά ένα, στην αντίθετη περίπτωση το 
μειώνουμε κατά ένα. Τότε ενημερώνουμε το τμήμα για τη νέα τιμή του Κ. Στο τέλος 
παράγουμε έναν τυχαίο αριθμό οχημάτων που προστίθενται στο κάθε διόδιο και 
επιστρέφουμε τον μετρητή vehicles_to_enter_counter.


                                        ---class segment---
---> H κλάση segment έχει 8 private members: την είσοδο του τμήματος, το num_of_vehicles που δείχνει πόσα οχήματα έχει κάθε τμήμα την τρέχουσα στιγμή, τη χωρητικότητα, το νούμερο του 
προηγούμενου και του επόμενου τμήματος, έναν δείκτη στην attica στην οποία ανήκει και το Κappa(K) και έναν δείκτη στην αρχική θέση του πίνακα vehicles.  

---> Στον constructor του δημιουργούμε την είσοδο του τμήματος, αρχικοποιούμε τη χωρητικότητα από τη γραμμή εντολών, δημιουργούμε έναν αρχικό αριθμό τυχαίων οχημάτων και φτιάχνουμε έναν πίνακα 
από rand_num_of_vehicles οχήματα. Στη συνέχεια δημιουργούμε rand_num_of_vehicles οχήματα. 

---> Στην μέθοδο get_vehicle δεχόμαστε τη θέση του πίνακα στην οποία είναι το όχημα που ψάχνουμε και επιστρέφουμε αυτό το όχημα.

---> Στην μέθοδο set_vehicle δεχόμαστε τη θέση του πίνακα και το όχημα που θέλουμε να περάσουμε σε αυτή τη θέση. Περνάμε το veh στη θέση i του πίνακα οχημάτων του τμήματος.

---> Στη μέθοδο enter καλείται η operate της εισόδου του κάθε τμήματος μέσα στην οποία γίνονται οι απαραίτητες διαδικασίες.

---> Στη μέθοδο exit χρησιμοποιούμε έναν δείκτη, τον copy_pointer προκειμένου να αντικαταστήσουμε τις ενδεχόμενες κενές θέσεις με τα οχήματα που παραμένουν στον πίνακα του segment. Για κάθε 
όχημα του segment, ελέγχουμε αν πρέπει να αποχωρήσει από τον αυτοκινητόδρομο, αν ναι, αυξάνουμε τον μετρητή οχημάτων που έφυγαν από την Αττική κατά 1 και κάνουμε τη θέση του οχήματος που έφυγε 
NULL. Αν δεν πρέπει να φύγει, ελέγχουμε αν ο copy_pointer δεν δείχνει στη θέση του οχήματος που εξετάζουμε τώρα, τότε, βάζουμε στη θέση που δείχνει ο copy_pointer το όχημα αυτό για να μην 
παραμείνει κενή και κάνουμε τη προηγούμενη θέση του οχήματος NULL και ύστερα αυξάνουμε τον copy_pointer για να εξετάσουμε την επόμενη θέση του πίνακα. Στο τέλος μειώνουμε τα οχήματα του 
τμήματατος σύμφωνα με τον counter.

---> Στη μέθοδο pass περνάμε στη μεταβλητή next_segment_num_of_vehicles τον αριθμό οχημάτων του επόμενου τμήματος. Κάνουμε false την κατάσταση ετοιμότητας του οχήματος που θα περάσουμε. Ύστερα 
περνάμε στην τελευταία θέση του πίνακα οχημάτων του επόμενου τμήματος το όχημα που θέλουμε να κάνουμε pass του segment που εξετάζουμε τώρα. Αυξάνουμε τα οχήματα του επόμενου τμήματος κατά ένα 
και κάνουμε NULL τη θέση του οχήματος που περάσαμε τώρα. Στο τέλος μειώνουμε τα οχήματα του τμήματατος κατά 1.
Ύστερα αν δεν βρισκόμαστε στο τελευταίο τμήμα της Αττικής, για να κάνουμε pass υπολογίζουμε σύμφωνα με το persent τα αυτοκίνητα που πρέπει να μεταβούν σε κατάσταση ετοιμότητας true. 
Επιλέγουμε τυχαίες θέσεις του πίνακα οχημάτων του segment και τότε αν το όχημα στη συγκεκριμένη θέση είναι σε κατάσταση ετοιμότητας false, την κάνουμε true. Σε αυτή τη διαδικασία μας βοηθάει 
ένας counter για να μετράμε για πόσα αυτοκίνητα ακόμα θα πρέπει να αλλάξουμε την κατάσταση ετοιμότητας. Yπολογίζουμε πόσα οχήματα είναι σε κατάσταση ετοιμότητας true και πρέπει να φύγουν από το 
segment. Αν αυτός ο αριθμός είναι μικρότερος ή ίσος της χωρητικότητας του επόμενου τμήματος, τότε περνάνε όλα τα οχήματα που βρίσκονται σε κατάσταση ετοιμότητας true, αλλιώς υπολογίζουμε πόσα 
χωράνε (num_of_exit_vehicles) στο επόμενο τμήμα και περνάμε τυχαία οχήματα από αυτό το τμήμα με κατάσταση ετοιμότητας true στο επόμενο τμήμα. Μετά αναδιαμορφώνουμε τον πίνακα οχημάτων 
ακολουθώντας την ίδια διαδικασία με τον copy_pointer που ακολουθήσαμε πριν στην exit. Επίσης χρησιμοποιούμε ένα flag για να δούμε αν τελικά χωρούσαν να περάσουν όλα τα οχήματα από το segment 
που βρίσκονταν σε κατάσταση ετοιμότητας true ή αν έχουν παραμείνει ακόμα κάποια (flag=true). 

---> ///EXIT/// Στη μέθοδο operate αρχικά κάνουμε exit τα αυτοκίνητα που πρέπει να φύγουν από τον αυτοκινητόδρομο. 
///PASS/// Καλείται η pass η οποία θα επιστρέψει ένα flag για να δούμε αν θα τυπωθούν καθυστερήσεις ή όχι και πού.
///ENTER/// Ύστερα κάνουμε enter τα οχήματα από τα διόδια της εισόδου του τμήματος. 
///PRINTS/// Χρησιμοποιούμε μία flag2 την οποία κάνουμε true αν ο αριθμός των οχημάτων που εισέρχονται στο τμήμα από την είσοδό του είναι μικρότερος από το πλήθος των οχημάτων που περιμένουν 
στην είσοδο και τυπώνουμε το μήνυμα "Delays in entrance of node ". Αν ισχύει flag, τυπώνουμε το μήνυμα "Delays after the node" και το όνομα του κόμβου της εισόδου του τμήματος. Αν ισχύουν και 
τα δύο αυτά, τυπώνουμε το μήνυμα "Keep a safe distance in the segment after the node " και το όνομα του κόμβου της εισόδου του τμήματος. 


                                        ---class attica---
---> Η attica έχει 3 private members, το num_of_vehicles που δείχνει πόσα οχήματα κινούνται στην αττική την τρέχουσα στιγμή, το Kappa (Κ), και έναν δείκτη στην αρχή του πίνακα segments. 

---> Στον construstor της δημιουργούμε έναν πίνακα με NSegs τμήματα. Όταν δημιουργούμε το πρώτο τμήμα, το previous_seg είναι -1 και όταν δημιουρούμε το τελευταίο τμήμα, το next_seg είναι -1. 

---> Σε όλα τα υπόλοιπα τμήματα το previous_seg είναι i-1, και το next_seg i+1. Ο δείκτης this δείχνει στην attica που ανήκει το κάθε τμήμα και το i αντιπροσωπεύει τον αριθμό του κόμβου κάθε 
εισόδου του τμήματος.

---> Στη μέθοδο get_segment δεχόμαστε τη θέση του πίνακα στην οποία είναι το τμήμα που ψάχνουμε και επιστρέφουμε αυτό το τμήμα.

---> Στη μέθοδο set_K ενημερώνουμε το Κ.

---> Στη μέθοδο operate προσπελαύνουμε τα τμήματα από το τελευταίο στο αρχικό. Καλούμε την operate κάθε τμήματος με ενημερωμένο το Κ και αυξάνουμε τον αριθμό των οχημάτων της Αττικής ανάλογα με 
το πόσα οχήματα κινούνται στο segment που εξετάζουμε εκείνη τη στιγμή. Τυπώνεται το πλήθος των οχημάτων του κάθε τμήματος και στο τέλος τυπώνεται ο αριθμός των οχημάτων όλης της Αττικής.


Τιμές παραμέτρων - ΔΟΚΙΜΕΣ:

1)  ./run 1 3 4 20

Attica Highway is in operation !!!
Give capacity for segment 0
20
Give capacity for segment 1
15
Give capacity for segment 2
30
Delays in entrance of node 2
Number of vehicles in Segment 2 : 10
Delays in entrance of node 1
Number of vehicles in Segment 1 : 12
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 14
Number of vehicles in Attica Highway : 43


               // pointer_to_attica->get_segment(previous)->set_num_of_vehicles(pointer_to_attica->get_segment(previous)->get_num_of_vehicles()-1);
                            //*vehicles[num_of_vehicles] = pointer_to_attica->get_segment(previous)->get_vehicle(rand_i);
                            //pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_exit_segment(-10);
                           
                            // int copy_pointer=0;  
                            // for(int i=0; i<prev_seg_veh; i++){
                                 
                            //     if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment() != -10) {
                            //         if(num_of_vehicles==1 || i!=copy_pointer) {
                            //             pointer_to_attica->get_segment(previous)->get_vehicle(copy_pointer) = pointer_to_attica->get_segment(previous)->get_vehicle(i);
                            //             pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(-10);
                            
                            //         }
                            //         copy_pointer++;
                            //     }  
                            // }



                            
            // num_of_pass_segment=0;
            // for(int i=0; i<prev_seg_veh; i++)                                                   // how many vehicles are ready
            //     if(pointer_to_attica->get_segment(previous)->get_vehicle(i).exit_segment()==true)
            //         num_of_pass_segment++;

            // if(capacity >= num_of_pass_segment) {   // can we fit them all?
            //     for(int i=0; i<prev_seg_veh; i++)                                               // pass the vehicles to the segment
            //         if(pointer_to_attica->get_segment(previous)->get_vehicle(i).exit_segment()==true) {
            //             pointer_to_attica->get_segment(previous)->get_vehicle(i).set_ready(false);
            //             pointer_to_attica->get_segment(previous)->get_vehicle(i).set_ready(seg_entrance->get_node()+1);
            //             pointer_to_attica->get_segment(previous)->set_num_of_vehicles(pointer_to_attica->get_segment(previous)->get_num_of_vehicles()-1);
            //             *vehicles[num_of_vehicles] = pointer_to_attica->get_segment(previous)->get_vehicle(i);
            //             pointer_to_attica->get_segment(previous)->get_vehicle(i).set_ready(-10);
            //             num_of_vehicles++;
            //         }   
                
            //     // int copy_pointer=0;     // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions
            //     // for(int i=0; i<prev_seg_veh; i++) {
            //     //     if(pointer_to_attica->get_segment(previous)->get_vehicle(i).get_exit_segment() != -10) {
            //     //         if(prev_seg_veh==1 || i!=copy_pointer) {
            //     //             pointer_to_attica->get_segment(previous)->get_vehicle(copy_pointer) = pointer_to_attica->get_segment(previous)->get_vehicle(i);
            //     //             pointer_to_attica->get_segment(previous)->get_vehicle(i).set_exit_segment(-10);
            //     //         }
            //     //         copy_pointer++;
            //     //     }
            //     // }  
            //     rebuild();   // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions
            // }
            // else {  // if they don't fit all
            //     flag=true;
            //     int num_of_exit_vehicles = num_of_pass_segment - (capacity - pointer_to_attica->get_segment(previous)->num_of_vehicles);

            //     while (num_of_exit_vehicles>0 && prev_seg_veh>0) {
            //         int rand_i = rand() % prev_seg_veh ;
            //         // we pass as many as random ready vehicles fit
            //         if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).is_gone() != true) {
            //             if(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).get_ready() == true) {
            //                 pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_ready(false);
            //                 pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).set_current_segment(seg_entrance->get_node()+1);
            //                 delete vehicles[num_of_vehicles];
            //                 vehicles[num_of_vehicles] = new vehicle(pointer_to_attica->get_segment(previous)->get_vehicle(rand_i));
            //                 pointer_to_attica->get_segment(previous)->get_vehicle(rand_i).time_to_go();
            //                  num_of_vehicles++;
            //                 num_of_exit_vehicles--;
            //                 pointer_to_attica->get_segment(previous)->rebuild();       // we should rebuild the array of vehicles of the previous segment so that the vehicles will be in continuous positions  
            //             }
            //         }
            //     }
            // }







                int counter=1;
    cout << "problhama     " << num_of_vehicles << endl;
    for(int i=0; i<num_of_vehicles; i++) {
        cout << "problhama" << i << endl;
        if(vehicles[i]->is_gone()) 
            break;
        counter++;
    }
    num_of_vehicles = counter;
