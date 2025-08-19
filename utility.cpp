namespace Utility{
    std::vector<int> string2Vector(std::string process){
        std::vector<int> build;
        std::string number = "";
        for(int i = 0; i < process.size(); i++) {
            if(process[i] == ' ' && number != "") {
                build.push_back(stoi(number));
                number = "";
            }
            else if(std::isdigit(process[i])) {
                number += process[i];
            }
            else{
                return {}; // invalid character included.
            }
        }
        // read last input in case list of numbers does not end with a space
        if(number != "") {
            build.push_back(stoi(number));
        }
        return build;
        }

    void outputVector(std::vector<int> given){
        std::cout << "{";
        for(int i = 0; i < given.size(); i++) {
            if(i == given.size()-1) {
                std::cout << given[i];
            } 
            else{
                std::cout << given[i] << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
        
};