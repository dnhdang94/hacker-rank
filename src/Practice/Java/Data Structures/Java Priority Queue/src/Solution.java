import java.util.*;

class Student {

    private int id;
    private String name;
    private double cgpa;

    public int getID() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getCGPA() {
        return cgpa;
    }

    public Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }
}

class Priorities {

    private PriorityQueue<Student> priorityQueue;

    public Priorities() {
        priorityQueue = new PriorityQueue<>(
                Comparator.comparing(Student::getCGPA).reversed()
                        .thenComparing(Student::getName)
                        .thenComparing(Student::getID)
        );
    }

    public List<Student> getStudents(List<String> events) {

        List<Student> students = new ArrayList<>();

        for (var event : events) {
            if (event.startsWith("SERVED")) {
                this.priorityQueue.poll();
            } else {
                String[] parts = event.split("\\s+");
                priorityQueue.add(
                        new Student(Integer.parseInt(parts[3]), parts[1], Double.parseDouble(parts[2]))
                );
            }
        }

        while (!this.priorityQueue.isEmpty()) {
            students.add(this.priorityQueue.poll());
        }

        return new ArrayList<>(students);
    }
}

public class Solution {

    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();

    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());
        List<String> events = new ArrayList<>();

        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }

        List<Student> students = priorities.getStudents(events);

        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st : students) {
                System.out.println(st.getName());
            }
        }
    }
}
