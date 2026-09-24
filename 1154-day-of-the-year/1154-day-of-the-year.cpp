class Solution {
public:
    int dayOfYear(string date) {
        int days =0;
        int daysmonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
          string sty = date.substr(0,4);
          int yy = stoi(sty);
          
          string stm = date.substr(5,2);
          int mm = stoi(stm);
          
          string std = date.substr(8,2);
          int dd = stoi(std);
          
          bool leap = (yy % 400 == 0 ) || (yy % 4 == 0 && yy % 100 != 0);
          if(leap){
            daysmonth[2]=29;
          }
          for(int i=1;i<mm;i++){
            days += daysmonth[i];
          }
          days += dd;
          return days;
    }
};