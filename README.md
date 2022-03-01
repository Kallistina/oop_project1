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
--->Στην κλάση αυτή υπάρχουν 3 private members: ο exit_node είναι ο τελικός κόμβος, δηλαδή ο προορισμός του κάθε οχήματος, το gone είναι μια λογική μεταβλητή μου δείχνει αν το συτοκίνητο βρίσκεται ακόμα στο κάθε segment και το ready αντιπροσωπεύει την κατάσταση ετοιμότητας.

H συνάρτηση random θα χρησιμοποιηθεί για την δημιουργία τυχαίων οχημάτων με τυχαίο exit_node που θα είναι ένας αριθμός ανάμεσα στο node του τμήματος στο οποίο θα δημιουργηθεί το όχημα και στον κόμβο τελικού τμήματος της attica.

---> Στον constuctor μέσω της μεταβλητής exit περνάμε τον τελικό κόμβο κάθε οχήματος. Αρχικοποιούμε το gone και το ready σε false. Έχουμε έναν copy constuctor για να αντιφράφουμε αυτοκίνητα.

---> Η get_ready επιστρέφει το ready και η set_ready ενημερώνει το ready.

---> H get_exit_node επιστρέφει το exit_node.

---> H exit_attica δέχεται το segment στο οποίο βρίσκεται τώρα το αυτοκίνητο. Μετά επιστρέφει αν είναι έτοιμο το όχημα να βγει από τον αυτοκινητόδρομο ανάλογα με το αν η συνθήκη exit_node==current_segment είναι αληθής ή όχι.

---> Η time_to_go κάνει τη μεταβλητή gone true, ώστε να ξέρουμε ότι πλέον αυτό το αυτοκίνητο δεν ανήκει σ'αυτό το τμήμα.

---> Η is_gone επιστρέφει το gone για να ξέρουμε ότι το αυτοκίνητο ανήκει ή δεν ανήκει σ'αυτό το τμήμα.




                                        ---class toll---
--->Η κλάση αυτή έχει 3 protected members, είναι υπερκλάση. Το πρώτο είναι μία queue με οχήματα, το δεύτερο ο αριθμός των οχημάτων που έχει κάθε στιγμή το διόδιο και το τρίτο είναι το Kappa, δηλαδή το Κ που αντιστοιχεί σε κάθε διόδιο.

---> Στον constuctor δημιουργείται ένας τυχαίος αριθμός οχημάτων. Σε κάθε όχημα περνάται τυχαίος αριθμός που αντιπροσωπεύει τον τελικό κόμβο και γίνεται push στην queue vehicles.

---> Στον destructor αδειάζει η queue vehicles.

---> Η μέθοδος get_num_of_vehicles επιστρέφει το num_of_vehicles.

---> Η συνάρτηση get_Κappa επιστρέφει τo Κappa.

---> Η συνάρτηση get_vehicle επιστρέφει reference στο πρώτο όχημα της queue vehicles.

---> Η συνάρτηση set_Kappa είναι pure virlual καθώς η υλοποίησή της διαφέρει ανάλογα με το αν το διόδιο είναι με εισπράκτορα ή ηλεκτρονικό.

---> Η μέθοδος add αυξάνει τον αρθμό των οχημάτων του διοδίου κάνοντας push στην queue ένα όχημα και η sub αντίστοιχα τo αφαιρεί.

---> Η toll είναι υπερκλάση και έχει δύο υποκλάσεις, την employe_toll και την electronic_toll. 




                                ---classes employe_toll και electronic_toll---
---> Κληρονομούν από την κλάση toll. 

---> Οι constructor τους γίνονται μέσω του constructor της υπερκλάσης και ενημερώνεται το Kappa ανάλογα με το είδος του διοδίου.

---> Η set_Κappa ενημερώνει την ταχύτητα με Κ στην employe_toll και με 2Κ στην electronic_toll.




                                        ---class entrance---
--->Η κλάση αυτή έχει 5 private members: το πρώτο είναι ο αριθμός των διοδίων της εισόδου, το δεύτερο είναι ο αριθμός των οχημάτων της εισόδου, το τρίτο είναι ο κόμβος της εισόδου, το τέταρτο 
είναι ο δείκτης στην αρχική θέση του πίνακα tolls και το πέμπτο είναι δείκτης στο segment της κάθε εισόδου.

---> Στον constructor δημιουργείται ένας τυχαίος αριθμός διοδίων με εισπράκτορα και ένας τυχαίος αριθμός ηλεκτρονικών διοδίων. Επίσης, δημιουργείται ένας πίνακας με num_of_tolls διόδια. Στη 
συνέχεια δημιουργούνται εναλλάξ διόδια με εισπράκτορα και ηλεκτρονικά διόδια. Σε κάθε διόδιο θέτουμε το Κ και τέλος υπολογίζουμε πόσα αυτοκίνητα έχει η είσοδος.

---> Η μέθοδος get_num_of_vehicles επιστρέφει τον αριθμό των οχημάτων της εισόδου.

---> Η συνάρτηση get_node επιστρέφει το όνομα/ταυτότητα του κόμβου της εισόδου.

---> Έχει destructor.

---> Η μέθοδος add δημιουργεί τυχαία αυτοκίνητα και τα προσθέτει σε όλα τα tolls της εισόδου.

---> H συνάρτηση operate έχει ορίσματα το NSegs και το Κ. Η operate έχει αρχικά έναν counter για τα οχήματα που εισέρχονται στα διόδια (vehicles_to_enter_counter) και 2 μεταβλητές για το όριο των 
οχημάτων που δέχεται το κάθε διόδιο ανάλογα με το αν είναι με εισπράκτορα ή ηλεκτρονικό (employe_tolls_limit και electronic_tolls_limit αντίστοιχα).

ΦΡΟΝΤΙΖΟΥΜΕ ΝΑ ΥΠΑΡΧΟΥΝ ΠΑΝΤΑ ΟΧΗΜΑΤΑ ΣΤΗΝ ΕΙΣΟΔΟ/ΔΙΟΔΙΑ.
Όσο (while)  η χωρητικότητα του τμήματος είναι αρκετή και δεν έχει ξεπεραστεί το όριο και των δύο ειδών διοδίων, περνάνε οχήματα από τα διόδια.

Αυτό γίνεται επαναληπτικά (for loop), ελέγχοντας αν επαρκεί η χωρητικότητα και αν ανάλογα με το είδος του διοδίου, που το ξεχωρίζουμε από την ταχύτητά του, μπορούν να περάσουν κι άλλα οχήματα από τα διόδια (αν 
ακόμη δεν έχει ξεπεραστεί το όριο του διοδίου). Περνάμε στο τέλος του πίνακα του segment το όχημα που εισέρχεται. Αφαιρούμε το όχημα από το διόδιο, μειώνουμε τα οχήματα της εισόδου κατά ένα και αυξάνουμε τον vehicles_to_enter_counter(τον μετρητή για το πόσα οήματα εισέρχονται από την είσοδο κάθε φορά).

Στο τέλος , μειώνουμε το όριο του διοδίου κατά ένα ανάλογα με το είδος του. Στην περίπτωση που η χωρητικότητα δεν επαρκεί, διακόπτουμε την εισαγωγή των οχημάτων στο τμήμα (break).

Αν το όριο των διοδίων με εισπράκτορα και των ηλεκτρονικών διοδίων μηδενίσει, δηλαδή αν περάσουν όλα τα αυτοκίνητα από τα διόδια, τότε αυξάνουμε το Κ κατά ένα, στην αντίθετη περίπτωση το 
μειώνουμε κατά ένα. Τότε ενημερώνουμε το τμήμα και τα διόδια για τη νέα τιμή του Κ. 

Προσθέτουμε κι άλλα τυχαία οχήματα στα διόδια και επιστρέφουμε τον μετρητή vehicles_to_enter_counter.


                                        ---class segment---
---> H κλάση segment έχει 6 private members: την είσοδο του τμήματος, το num_of_vehicles που δείχνει πόσα οχήματα έχει κάθε τμήμα την τρέχουσα στιγμή, τη χωρητικότητα, το Κappa, έναν δείκτη στην attica στην οποία ανήκει και έναν δείκτη στην αρχική θέση του πίνακα vehicles.  

---> Η ενημερώνει το Κ του τμήματος και της Αττικής.

---> Στην μέθοδο get_vehicle δεχόμαστε τη θέση του πίνακα στην οποία είναι το όχημα που ψάχνουμε και επιστρέφουμε αυτό το όχημα.

---> Στην μέθοδο set_vehicle δεχόμαστε τη θέση του πίνακα και το όχημα που θέλουμε να περάσουμε σε αυτή τη θέση. Διαγράφουμε το αυτοκίνητο που υπήρχε και δημιουργούμε ένα νέο αντίγραφο του veh στη θέση i του πίνακα οχημάτων του τμήματος. Κάνουμε την κατάσταση ετοιμότητας false και αυξάνουμε τα οχήματα του τμήματος κατα 1.

----> Η get_num_of_vehicles επιστρέφει τον αριθμό των οχημάτων του τμήματος.

----> Η set_num_of_vehicles αυξάνει ή μειώνει τον αριθμό των οχημάτων του τμήματος ανάλογα με το όρισμα που δέχεται.

----> Η επιστρέφει get_capacity τη χωρητικότητα του τμήματος.

---> Στον constructor του δημιουργούμε την είσοδο του τμήματος, αρχικοποιούμε τη χωρητικότητα από τη γραμμή εντολών, δημιουργούμε έναν αρχικό αριθμό τυχαίων οχημάτων και φτιάχνουμε έναν πίνακα 
από rand_num_of_vehicles οχήματα. Στη συνέχεια δημιουργούμε rand_num_of_vehicles οχήματα. 

---> Στη μέθοδο rebuild ουστιαστικά χρησιμοποιούμε τη bubble sort για να μαζέψουμε στην αρχή του πίνακα vehicles όλα τα αυτοκίνητα με gone 0, δηλαδή αυτά που βρίσκονται ακόμα στο segment και στο τέλος αυτά με gone 1, δηλαδή αυτά που έχουν φύγει.

---> Στη μέθοδο enter καλείται η operate της εισόδου του κάθε τμήματος μέσα στην οποία γίνονται οι απαραίτητες διαδικασίες.
Ενημερώνεται η attica για το πόσα αυτοκίνητα προστέθηκαν από τα διόδια της εισόδου.
Επιστρέφει τον αριθμό των οχημάτων που προστέθηκαν από τα διόδια της εισόδου.

---> Στη μέθοδο exit ελέγχουμε για όλα τα αυτοκίνητα αν είναι ακόμα μέσα στο τμήμα και αν είναι έτοιμα να φύγουν από την Αττική. Αν ναι, καλούμε την time_to_go, δηλαδή τα διώχνουμε απ'το τμήμα, μειώνουμε τον αριθμό του τμήματος και της Αττικής κατά 1.
Σε περίπτωση που αποχώρησε έστω ένα όχημα(μας το δείχνει η flag) καλούμε τη rebuild για να φτιάξει τον πίνακα vehicles.

---> Στη μέθοδο pass το passed_vehicles είναι ένας μετρητής που μετράει πόσα αυτοκίνητα πέρασαν στο τρέχον τμήμα κάθε φορά που καλείται η μέθοδος pass. To ready_vehicles είναι το σύνολο των οχημάτων αυτού του τμήματος που βρίσκονται σε κατάσταση "ετοιμότητας". Αν το previous_segment δεν είναι το -1, δηλαδή δεν βρισκόμαστε στο πρώτο segment, τότε αν τα αυτοκίνητα του previous_segment δεν είναι 0 (prev_seg_veh!=0), υπολογίζουμε πόσα αυτοκίνητα πρέπει σε κατάσταση ετοιμότητας. Ύστερα, θέτουμε σε ετοιμότητα τυχαία αυτοκίνητα του previous_segment.
Όσο το τρέχον τμήμα χωράει αυτοκίνητα και ο μετρητής οχημάτων που είναι σε ετοιμότητα δεν είναι 0, περνάμε αυτοκίνητα από το previous_segment στο τρέχον segment. Επιλέγουμε πάλι τυχαία θέση οχήματος από το previous_segment και αν αυτό το όχημα είναι σε κατάσταση ετοιμότητας το περνάμε στο τρέχον τμήμα. Διαγράφουμε το όχημα που μπορεί να υπάρχει μετά το τελευταίο όχημα που μπήκε στον πίνακα vehicles του τρέχοντος τμήματος. Ύστερα, δημιουργούμε ένα καινούριο αντίγραφο του οχήματος που θέλουμε να περάσουμε από το previous_segment σε αυτή τη θέση και το περνάμε. Διώχνουμε από το προηγούμενο segment το όχημα που αντιγράψαμε καλώντας την time_to_go. Mειώνουμε τα αυτοκίνητα του previous_segment κατά 1. Καλούμε τη rebuild για το προηγούμενο τμήμα ώστε να βρίσκονται όλα τα αυτοκίνητα που δεν έχουν φύγει σε συνεχόμενες θέσεις. Τέλος, μειώνουμε τον μετρητή ready_vehicles και αυξάνουμε τον passed_vehicles.
Αν τα αυτοκίνητα του previous_segment που είναι σε ετοιμότητα είναι περισσότερα από αυτά που πέρασαν στο τρέχον τμήμα επιστρέφουμε true, αλλιώς false (θα μας χρειαστεί αργότερα στην operate του segment για τις εκτυπώσεις).

--->  Στη μέθοδο operate ///EXIT///αρχικά κάνουμε exit τα αυτοκίνητα που πρέπει να φύγουν από τον αυτοκινητόδρομο. 

///PASS/// Καλείται η pass η οποία θα επιστρέψει ένα flag για να δούμε αν θα τυπωθούν καθυστερήσεις ή όχι και πού.

///ENTER/// Ύστερα κάνουμε enter τα οχήματα από τα διόδια της εισόδου του τμήματος, αν χωράνε βέβαια. 

///PRINTS/// Χρησιμοποιούμε μία flag2 την οποία κάνουμε true αν ο αριθμός των οχημάτων που εισέρχονται στο τμήμα από την είσοδό του είναι μικρότερος από το πλήθος των οχημάτων που περιμένουν στην είσοδο και τυπώνουμε το μήνυμα "Delays in entrance of node ". 
Αν ισχύει και η flag, τυπώνουμε το μήνυμα "Delays after the node" και το όνομα του κόμβου της εισόδου του τμήματος. 
Αν δεν ισχύει κανένα, τυπώνουμε το μήνυμα "Keep a safe distance in the segment after the node " και το όνομα του κόμβου της εισόδου του τμήματος. 




                                        ---class attica---
---> Η attica έχει 4 private members, το num_of_vehicles που δείχνει πόσα οχήματα κινούνται στην αττική την τρέχουσα στιγμή, το num_of_segments που είναι ο αριθμός των τμημάτων της, το Kappa είναι το Κ και έναν δείκτη στην αρχή του πίνακα segments. 

---> Στον construstor της δημιουργούμε έναν πίνακα με NSegs τμήματα. Σε όλα τα τμήματα περνάμε τον αριθμό των τνημάτων της Αττικής, το Κ, το i που αντιπροσωπεύει τον αριθμό του κόμβου κάθε εισόδου του τμήματος και έναν δείκτη this που δείχνει στην attica που ανήκει το κάθε τμήμα.

---> Έχει destructor.

---> Στη μέθοδο get_segment δεχόμαστε τη θέση του πίνακα στην οποία είναι το τμήμα που ψάχνουμε και επιστρέφουμε αυτό το τμήμα.

---> Στη μέθοδο set_K ενημερώνουμε το Κ.

---> Στη μέθοδο ενημαρώνουμε τον αριθμό των οχημάτων.

---> Στη μέθοδο operate προσπελαύνουμε τα τμήματα από το τελευταίο στο αρχικό. Καλούμε την operate κάθε τμήματος με ενημερωμένο το Κ. 
Τυπώνεται για κάθε κύκλο το πλήθος των οχημάτων του κάθε τμήματος και στο τέλος τυπώνεται ο αριθμός των οχημάτων όλης της Αττικής.




Τιμές παραμέτρων - ΔΟΚΙΜΕΣ:

1)  ./run 1 3 4 20
για capacity : 50,60,35 αντίστοιχα

Give capacity for segment 0
50
Give capacity for segment 1
60
Give capacity for segment 2
35

Attica Highway is in operation !!!

Give capacity for segment 0
50

Give capacity for segment 1
60

Give capacity for segment 2
35

Keep a safe distance in the segment after the node 2
Number of vehicles in Segment 2 : 12
Keep a safe distance in the segment after the node 1
Number of vehicles in Segment 1 : 15
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 13
Number of vehicles in Attica Highway : 40


1)  ./run 2 5 10 70
για capacity : 60,100,20,5,200 αντίστοιχα

Attica Highway is in operation !!!

Give capacity for segment 0
60

Give capacity for segment 1
100

Give capacity for segment 2
20

Give capacity for segment 3
5

Give capacity for segment 4
200

Keep a safe distance in the segment after the node 4
Number of vehicles in Segment 4 : 31
Delays in entrance of node 3
Number of vehicles in Segment 3 : 5
Delays after the node 2
Number of vehicles in Segment 2 : 20
Keep a safe distance in the segment after the node 1
Number of vehicles in Segment 1 : 33
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 31
Number of vehicles in Attica Highway : 120

Delays after the node 4
Number of vehicles in Segment 4 : 50
Delays in entrance of node 3
Delays after the node 3
Number of vehicles in Segment 3 : 5
Delays after the node 2
Number of vehicles in Segment 2 : 20
Delays after the node 1
Number of vehicles in Segment 1 : 59
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 58
Number of vehicles in Attica Highway : 192


3)./run 10 3 5 50
για capacity : 10,20,80 αντίστοιχα

Attica Highway is in operation !!!

Give capacity for segment 0
10

Give capacity for segment 1
20

Give capacity for segment 2
80

Keep a safe distance in the segment after the node 2
Number of vehicles in Segment 2 : 16
Keep a safe distance in the segment after the node 1
Number of vehicles in Segment 1 : 15
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 41

Delays after the node 2
Number of vehicles in Segment 2 : 26
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 56

Delays after the node 2
Number of vehicles in Segment 2 : 38
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 68

Delays after the node 2
Number of vehicles in Segment 2 : 55
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 85

Delays after the node 2
Number of vehicles in Segment 2 : 74
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 104

Delays after the node 2
Number of vehicles in Segment 2 : 80
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 110

Delays after the node 2
Number of vehicles in Segment 2 : 80
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 110

Delays after the node 2
Number of vehicles in Segment 2 : 80
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 110

Delays after the node 2
Number of vehicles in Segment 2 : 80
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 110

Delays after the node 2
Number of vehicles in Segment 2 : 80
Delays after the node 1
Number of vehicles in Segment 1 : 20
Keep a safe distance in the segment after the node 0
Number of vehicles in Segment 0 : 10
Number of vehicles in Attica Highway : 110