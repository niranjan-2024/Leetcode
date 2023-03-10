/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */

let b,m,s;

var ParkingSystem = function(big, medium, small) {
    b = big;
    m = medium;
    s = small;
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(carType) {
    if(carType == 1){
        if(b != 0){
            b--;
            return true;
        }
    }
    else if(carType == 2){
        if(m != 0){
            m--;
            return true;
        }
    }
    else{
        if(s != 0){
            s--;
            return true;
        }
    }
    
    return false;
};

/** 
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */