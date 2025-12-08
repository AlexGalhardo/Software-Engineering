# S.O.L.I.D Principles

### S ingle Responsibility Principle

- Imagine that you have a toy that only does one thing, like a remote control car that only drives. This car only has to worry about driving well. In programming, a class should do one thing and do it well, just like the car.

```ts
// Each class should have a single responsibility.

// Wrong: The class is doing more than one thing.
class UserWrong {
  constructor(
    public name: string,
    public email: string
  ) {}

  getUserName(): string {
    return this.name;
  }

  getUserEmail(): string {
    return this.email;
  }

  saveToDatabase() {
    // save database
  }
}

// Right: Separate responsibilities into different classes.
class User {
  constructor(
    public name: string,
    public email: string
  ) {}

  getUserName(): string {
    return this.name;
  }

  getUserEmail(): string {
    return this.email;
  }
}

class UserRepository {
  saveToDatabase(user: User) {
    // save database
  }
}
```

### O pen/Closed Principle

- Think of a game of building blocks. You can add new blocks to create new things, but you don't need to break the blocks you've already built. In programming, this means that we can add new functionality without changing what's already working.

```ts
// Software should be open for extension, but closed for modification.

// Wrong: We need to modify the class to add new functionality.
class RectangleWrong {
  constructor(
    public width: number,
    public height: number
  ) {}

  area(): number {
    return this.width * this.height;
  }
}

class AreaCalculatorWrong {
  calculateArea(shape: any): number {
    if (shape instanceof Rectangle) {
      return shape.area();
    }
    return 0;
  }
}

// Right: We added new functionality without modifying existing code.
interface Shape {
  area(): number;
}

class Rectangle implements Shape {
  constructor(
    public width: number,
    public height: number
  ) {}

  area(): number {
    return this.width * this.height;
  }
}

class Circle implements Shape {
  constructor(public radius: number) {}

  area(): number {
    return Math.PI * this.radius * this.radius;
  }
}

class AreaCalculator {
  calculateArea(shape: Shape): number {
    return shape.area();
  }
}
```

### L iskov Substitution Principle

- Imagine that you have a toy that can be replaced with another similar one without any problems, like swapping a toy car for a toy truck. In programming, this means that we can replace a class with another that does something similar, and everything should still work fine.

```ts
// Objects must be substitutable for their subtypes without changing the behavior of the program.

// Wrong: Subclass changes superclass behavior.
class BirdWrong {
  fly(): void {
    console.log("Flying");
  }
}

class PenguinWrong extends BirdWrong {
  fly(): void {
    throw new Error("Penguins can't fly");
  }
}

// Correct: Subclass maintains the expected behavior of the superclass.
abstract class Bird {
  abstract move(): void;
}

class Sparrow extends Bird {
  move(): void {
    console.log("Flying");
  }
}

class Penguin extends Bird {
  move(): void {
    console.log("Swimming");
  }
}
```

### I nterface Segregation Principle

- Think of a remote control that has many buttons, but you only use a few. It would be better to have smaller, specific remote controls for each thing. In programming, this means that it is better to have smaller, specific interfaces than one large, complex interface.

```ts
// Clients should not be forced to rely on interfaces they do not use.

// Wrong: Large interface with methods that some classes don't need.
interface WorkerHuman {
  work(): void;
  eat(): void;
}

class HumanWorkerWrong implements WorkerHuman {
  work(): void {
    console.log("Working");
  }

  eat(): void {
    console.log("Eating");
  }
}

class RobotWorkerWrong implements WorkerHuman {
  work(): void {
    console.log("Working");
  }

  eat(): void {
    // Robots don't eat
  }
}

// Right: Specific interfaces for each functionality.
interface Workable {
  work(): void;
}

interface Eatable {
  eat(): void;
}

class HumanWorker implements Workable, Eatable {
  work(): void {
    console.log("Working");
  }

  eat(): void {
    console.log("Eating");
  }
}

class RobotWorker implements Workable {
  work(): void {
    console.log("Working");
  }
}
```

### D ependency Inversion Principle

- Imagine that instead of toys that need special parts to work, you have toys that can work with any common part. In programming, this means that classes should depend on abstractions (general ideas) rather than on specific, concrete things, so that it is easy to swap out parts.

```ts
// High-level modules should not depend on low-level modules. Both should depend on abstractions.

// Wrong: The class depends on a concrete implementation.
class LightBulbWrong {
  turnOn(): void {
    console.log("LightBulb on");
  }

  turnOff(): void {
    console.log("LightBulb off");
  }
}

class SwitchWrong {
  private lightBulb: LightBulbWrong;

  constructor(lightBulb: LightBulbWrong) {
    this.lightBulb = lightBulb;
  }

  operate(): void {
    this.lightBulb.turnOn();
  }
}

// Correct: The class depends on an abstraction.
interface Switchable {
  turnOn(): void;
  turnOff(): void;
}

class LightBulb implements Switchable {
  turnOn(): void {
    console.log("LightBulb on");
  }

  turnOff(): void {
    console.log("LightBulb off");
  }
}

class Switch {
  private device: Switchable;

  constructor(device: Switchable) {
    this.device = device;
  }

  operate(): void {
    this.device.turnOn();
  }
}
```
