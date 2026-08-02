//Your code goes here

abstract class Animal {
    protected String name;

    Animal(String name) {
        this.name = name;
    }

    abstract void makeSound();
}

class Dog extends Animal {
    Dog(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println("The dog "+ name +  " says : Woof!");
    }
}

class Cat extends Animal {
    Cat(String name) {
        super(name);
    }
    @Override
    void makeSound() {
    System.out.println("The cat "+ name + " says : Meow!");
}
}



//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your abstract class `Animal` and the drived classes 'Dog', 'Cat'.

First the object of the class Dog is created along with the dog name.
Then the Dog class object is used to call the Method makeSound() to print the corresponding text of Dog class.

Next the object of the class Cat is created along with the cat name.
Then the Cat class object is used to call the Method makeSound() to print the corresponding text of Cat class.


public class Main {

    public static void main(String[] args) {
    
        Scanner scanner = new Scanner(System.in);
        
        // Input names for dog and cat
        
        String dName = scanner.nextLine();
        String cName = scanner.nextLine();

            
        // Create Dog objects
        Animal dog = new Dog(dName);
        dog.makeSound();

        // Create Cat objects
        Animal cat = new Cat(cName);
        cat.makeSound();


        scanner.close();
    }
}

*/

/*
//Below are the output statements

System.out.println("The dog " + name + " says : Woof!");
System.out.println("The cat " + name + " says : Meow!");

*/
