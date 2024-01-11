using namespace std;


bool oneEdit(string stringOne, string stringTwo) {
    // Write your code here.


    int dif = stringOne.size() - stringTwo.size();

    if(abs(dif) > 1){
        //return false if the length difference is bigger than 1
        return false;
    }
    else if(dif == 0){
        //check if only one character differs
        int difference = 0;
        for(int i = 0; i < stringOne.size(); i++){
            if(stringOne[i] != stringTwo[i]) difference++;
        }
        //return false if there's more than one difference
        if(difference > 1) return false;
        else return true;
    }
    else {
        int change = 0;
        if (dif > 0) {
            for (int i = 0, z = 0; i < stringTwo.size(); i++, z++) {
                if (stringOne[z] == stringTwo[i]) continue;
                else {
                    z++;
                    cout << stringOne[z] << stringTwo[i] << endl;
                    if (stringOne[z] != stringTwo[i]) return false;
                    else change++;
                }
            }
        } else {
            for (int i = 0, z = 0; i < stringOne.size(); i++, z++) {
                if (stringOne[i] == stringTwo[z]) continue;
                else {
                    z++;
                    if (stringOne[i] != stringTwo[z]) return false;
                    else change++;
                }
            }

        }
        if (change > 1) return false;
        else return true;
    }
}
