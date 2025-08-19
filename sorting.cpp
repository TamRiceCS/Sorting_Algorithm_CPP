namespace Sorting {
    // All algorithms must be pass by value and not pass by reference. DO NOT OVERWRITE ORIGINAL!
    void bubbleSort(std::vector<int> base){
        std::cout << "\nStarting bubble sort:" << std::endl;
        Utility::outputVector(base);
        for(int i = 0; i < base.size()-2; i++) {
            for(int j = base.size()-1; j > 0; j--) {
                if(base[j] < base[j-1]) {
                    std::swap(base[j], base[j-1]);
                    std::cout << "\n" << base[j] << " has been bubble swapped with " << base[j-1] << std::endl;
                    Utility::outputVector(base);
                }
            }
        }
        std::cout << "\nSort completed. Time = O(n^2) and Space = O(1)" << std::endl;
        std::cout << std::endl;
    }
    void selectionSort(std::vector<int> base){
        int min = base.size()-1;
        for(int i = 0; i < base.size()-1; i++) {
            for(int j = i; j < base.size()-1; j++) {
                if(base[j] < base[min]) {
                    min = j;
                    std::cout << "We found a new min in the unsorted area it is: " << base[min] << std::endl;
                }
            }
            std::cout << "Place local min into end of sorted section..." << std::endl;
            std::swap(base[min], base[i]);
            min = base.size()-1;
            Utility::outputVector(base);
            std::cout << "\n";
        }
        std::cout << "\nSort completed. Time = O(n^2) and Space = O(1)" << std::endl;
        std::cout << std::endl;
    }
    void insertionSort(std::vector<int> base){
        int place = 0;
        for(int i = 1; i < base.size(); i++) {
            int save = base[i]; // save insert value
            base[i] = base[i-1]; // overwrite insert value
            place = i-1;
            while(base[place] > save && place >= 0){ 
                std::cout << "Have to shift forward: ";
                base[place+1] = base[place];
                Utility::outputVector(base);
                place--;
            }
            std::cout << "Found place to insert: ";
            base[place+1] = save;
            Utility::outputVector(base);
            std::cout << "\n";
        }
        std::cout << "\nSort completed. Time = O(n^2) and Space = O(1)" << std::endl;
        std::cout << std::endl;
    }
    void helperMerge(int s1, int s2, int e1, int e2, std::vector<int>& base) {

        std::vector<int> left((e1-s1)+1, 0);
        std::vector<int> right((e2-s2)+1, 0);

        int lptr = 0;
        int rptr = 0;

        for(int i = s1; i <= e1; i++) {
            left[lptr] = base[i];
            lptr++;
        }

        for(int i = s2; i <= e2; i++) {
            right[rptr] = base[i];
            rptr++;

        }

        std::cout << "\nLeft split to merge: ";
        Utility::outputVector(left);
        std::cout << "Right split to merge: ";
        Utility::outputVector(right);

        lptr = 0;
        rptr = 0;

        for(int i = s1; i <= e2; i++) {
            if(lptr >= left.size()) {
                std::cout << "Placed r1 " << right[rptr] << std::endl;
                base[i] = right[rptr++];
            }
            else if(rptr >= right.size()) {
                std::cout << "Placed l1 " << left[lptr] << std::endl;
                base[i] = left[lptr++];
            }
            else if(left[lptr] < right[rptr]) {
                std::cout << "Placed l2 " << left[lptr] << std::endl;
                base[i] = left[lptr++];
            }
            else{
                std::cout << "Placed r2 " << right[rptr] << std::endl;
                base[i] = right[rptr++];
                
            }
        }

        std::cout << "Merge Complete: ";
        Utility::outputVector(base);


    }
    void mergeSort(std::vector<int>& base, int start, int end){
        if(start >= end) {
            return;
        }

        int middle = (start + end) / 2;
        mergeSort(base, start, middle);
        mergeSort(base, middle+1, end);
        helperMerge(start, middle+1, middle, end, base);
    }
    void quickSort(std::vector<int>& base, int start, int end){
        if(start >= end) {
            return;
        }

        std::cout << "\nWorking range is from " << start << " to " << end << std::endl;

        int pivot = end;
        int swapPt = start; 

        for(int i = start; i < end; i++) {
            if(base[i] < base[pivot]) {
                std::swap(base[i], base[swapPt]);
                std::cout << "Swaped: " << base[i] << " and  " << base[swapPt] << ": ";
                Utility::outputVector(base);
                swapPt++;
            }
        }

        std::swap(base[end], base[swapPt]);
        std::cout << "Swap the pivot to the correct position: ";
        Utility::outputVector(base);

       

        quickSort(base, start, swapPt-1);
        quickSort(base, swapPt, end);


    }
};