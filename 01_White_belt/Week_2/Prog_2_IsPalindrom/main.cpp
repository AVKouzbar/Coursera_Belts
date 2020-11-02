bool IsPalindrom (string w) {
    int c = 0;
           for (int i = 0; i <= w.size() ; ++i) {
            if ( w [i]  ==  w [w.size() - i - 1]   ) {
                c++;
            } else return false ;
            if ( c == (w.size() - 1) / 2 || w.size()  == 1 || w.size() < 1   ) { return true; }
            }
}



