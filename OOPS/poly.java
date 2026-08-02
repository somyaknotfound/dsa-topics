//Your code goes here

class ShapeCalculator {
    public void area(int radius) {
        double ans = 3.14*radius*radius;
        System.out.println("Area of Circle : "+ (int)ans);
    }
    public void area(int length , int width) {
        int ans = length*width;
        System.out.println("Area of Rectangle : "+ ans);
    }
    public void area(int base1 , int base2 , int height) {
        double ans = 0.5*((base1 + base2)*height);
        System.out.println("Area of Trapezoid : "+ (int)ans);
    }
}



//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `ShapeCalculator`.

It creates a object of class `ShapeCalculator`.
It then calls the area method with radius as an argument. The method calculates the area of Circle and prints it.
It then calls the area method with length and width as arguments. The method calculates the area of Rectangle and prints it.
It then calls the area method with base1, base2, height as arguments. The method calculates the area of Trapezoid and prints it.


public class Main {

    public static void main(String[] args) {
    
        Scanner scanner = new Scanner(System.in);
        
        int radius = scanner.nextInt();
        int length = scanner.nextInt();
        int width = scanner.nextInt();
        int base1 = scanner.nextInt();
        int base2 = scanner.nextInt();
        int height = scanner.nextInt();

        ShapeCalculator sc = new ShapeCalculator();
        sc.area(radius);
        sc.area(length, width);
        sc.area(base1, base2, height);

        scanner.close();
    }
}

*/

/*
//Below are the output statements

System.out.println("Area of Circle : " + result);
System.out.println("Area of Rectangle : " + result);
System.out.println("Area of Trapezoid : " + result);

*/
