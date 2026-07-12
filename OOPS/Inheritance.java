import java.util.*;

// Base class Employee
class Employee {
    protected String name;
    protected int id;

    // Constructor for Employee
    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    // Method to display details
    public void displayDetails() {
        System.out.println("Name : " + name);
        System.out.println("Id : " + id);
    }
}

// Derived class Manager
class Manager extends Employee {
    private int teamSize;

    // Constructor for Manager
    public Manager(String name, int id, int teamSize) {
        super(name, id);
        this.teamSize = teamSize;
    }

    @Override
    public void displayDetails() {
        super.displayDetails(); // Call to Employee displayDetails
        System.out.println("Team Size : " + teamSize);
    }
}

// Derived class Engineer
class Engineer extends Employee {
    private String specialization;

    // Constructor for Engineer
    public Engineer(String name, int id, String specialization) {
        super(name, id);
        this.specialization = specialization;
    }

    @Override
    public void displayDetails() {
        super.displayDetails(); // Call to Employee displayDetails
        System.out.println("Specialization : " + specialization);
    }
}

class Main {
    public static void main(String[] args) {
        // Hardcoded Manager input
        String M_name = "Jax";
        int M_id = 101;
        int M_teamSize = 8;

        // Hardcoded Engineer input
        String E_name = "William";
        int E_id = 202;
        String E_specialization = "Backend Developer";

        // Create Manager object
        Manager manager = new Manager(M_name, M_id, M_teamSize);
        System.out.println("Manager Details");
        manager.displayDetails();

        System.out.println();

        // Create Engineer object
        Engineer engineer = new Engineer(E_name, E_id, E_specialization);
        System.out.println("Engineer Details");
        engineer.displayDetails();
    }
}
