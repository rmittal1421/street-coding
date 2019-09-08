/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    let d = new Date(year, month - 1, day, 0, 0, 0, 0);
    switch(d.getDay()) {
        case 0: 
            return "Sunday";
        case 1: 
            return "Monday";
        case 2: 
            return "Tuesday";
        case 3: 
            return "Wednesday";
        case 4: 
            return "Thursday";
        case 5: 
            return "Friday";
        case 6: 
            return "Saturday";
    }
};
