# Tests

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/types-tests.png">

## **References**

- Books
  - [Test Driven Development: By Example - Kent Beck](https://www.amazon.com/Test-Driven-Development-Kent-Beck/dp/0321146530)
- Tools
  - [Jest](https://jestjs.io/)
  - [Vitest](https://vitest.dev/)
  - [Bun Test Runner](https://bun.sh/docs/cli/test)
  - [Cypress](https://www.cypress.io/)
  - [Playwright](https://playwright.dev/)
  - [k6](https://k6.io/)
  - [Artillery](https://github.com/artilleryio/artillery)

## **Unit Testing**

- What it is: Testing a very small part of the program, such as a specific function, to see if it is working properly.
- Example: Checking if a function to add two numbers is actually adding correctly.

## **Integration Testing**

- What it is: Testing if different parts of the program work well together.
- Example: Checking if a function to add works well together with a function that displays the result on the screen.

## **System Testing (End to End Testing)**

- What it is: Testing the entire program to see if it is working as it should.
- Example: Checking if a drawing application allows you to draw, save and open drawings correctly.

## **Acceptance Testing**

- What it is: Testing if the program meets the needs and expectations of users.
- Example: Checking if a computer game is fun and easy to play, as players expect.

## **Regression Testing**

- What it is: Testing the program after making changes to ensure that nothing broke.
- Example: Checking if after adding a new character to the game, the old characters still work well.

## **Performance Testing**

- What it is: Testing whether the program works quickly and well even when many people are using it.
- Example: Checking whether a website doesn't slow down when many people are accessing it at the same time.

## **Load Testing**

- What it is: Testing whether the program can handle a large number of users or a lot of information at the same time.
- Example: Checking whether a game server can handle 1000 players online at the same time without crashing.

## **Security Testing**

What it is: Testing whether the program is safe against people who try to do bad things, like stealing data.
Example: Checking whether an online store protects customers' credit card information well.

## **Usability Testing**

What it is: Testing whether the program is easy to use and understand.
Example: Checking whether a drawing application is easy for children to understand and use.

## **Compatibility Testing**

What it is: Testing whether the program works well on different devices and operating systems.
Example: Checking whether a music application works on both iPhones and Android phones.

### **In short**

- Unit Testing: Tests small parts.
- Integration Testing: Tests whether parts work together.
- System Testing: Tests the entire program.
- Acceptance Testing: Tests whether users like it.
- Regression Testing: Tests after changes.
- Performance Testing: Tests speed and efficiency.
- Load Testing: Tests capacity.
- Security Testing: Tests protection.
- Usability Testing: Tests ease of use.
- Compatibility Testing: Tests on different devices.

## **TDD - Test Driven Development**

- Is a software development practice where you write tests before you write the code that will make those tests pass. Here’s a simple summary of the process:
  - Write a Test: First, you write a small test for a feature you want to implement. This test should initially fail, because the feature hasn’t been created yet.
  - Write the Code: Next, you write the code needed to make the test pass. The code should be as simple as possible to meet the requirements of the test.
  - Run the Test: You run the test to verify that the new code makes the test pass. If the test passes, then the feature has been implemented correctly.
  - Refactor the Code: Lastly, you can improve or “clean up” the code, ensuring that it remains simple, efficient, and maintainable without breaking functionality.
  - Iterate: You repeat these steps for each new feature you want to add.
- The whole idea of ​​TDD is to ensure that every piece of your code is tested from the beginning, helping to prevent bugs and making it easier to maintain and evolve the software.

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/tdd.png">

## **Arrange, Act, Assert**

- Is a simple and organized way to write software tests.
- AAA stands for:
  - Arrange: Prepare everything you need for the test. This can include setting up objects, variables, and initial states.
  - Act: Perform the action or behavior you want to test. This can be calling a function or method.
  - Assert: Verify that the result of the action is what you expected. Here, you compare the result you got with the expected result.
- In short:
  - Arrange: Set the stage.
  - Act: Execute the action.
  - Assert: Verify the result.
- AAA helps make tests clear and structured, making them easier to read and maintain.

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/test-aaa.png">

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/test-aaa-example.png">

## **Functional and Non-Functional Tests**

- Functional Tests
  - What are they?
    - Tests that verify whether the software does what it should do.
    - Example:
      - If you have a calculator application, a functional test verifies whether 2 + 2 actually equals 4.
    - Focus:
      - Functionality and system requirements.
      - Test things like: login, registration, calculations, sending emails, etc.
- Non-Functional Tests
  - What are they?
    - Tests that verify how the software behaves.
    - Example:
      - If the calculator works correctly when 1000 people use it at the same time.
    - Focus:
      - Quality and features of the system.
      - Test things like: performance (speed), security, usability, reliability, etc.
- In short
  - Functional Tests: Verify what the software does.
  - Non-Functional Tests: Verify how the software does it.

## **Mocks, Stubs, Fakes and Spies**

### Mocks

- Mocks are objects that simulate the behavior of real objects.
- They are configured to wait for specific calls and respond in a controlled manner.

  - How are they used?
    - Used to verify that certain interactions occur during testing.
    - Example: You want to ensure that a sendEmail method is called when a new user registers

- userService.ts

```ts
// userService.ts
import axios from "axios";

export interface User {
  id: number;
  name: string;
}

export async function getUser(userId: number): Promise<User> {
  const response = await axios.get<User>(
    `https://api.example.com/users/${userId}`
  );
  return response.data;
}
```

- userService.test.ts

```ts
import axios from "axios";
import { getUser, User } from "./userService";

// Mocking the axios module
jest.mock("axios");
const mockedAxios = axios as jest.Mocked<typeof axios>;

describe("getUser", () => {
  it("should return user data when the API responds correctly", async () => {
    // Arrange
    const userId = 1;
    const userData: User = { id: userId, name: "John Doe" };
    mockedAxios.get.mockResolvedValue({ data: userData });

    // Act
    const result = await getUser(userId);

    // Assert
    expect(result).toEqual(userData);
    expect(mockedAxios.get).toHaveBeenCalledWith(
      `https://api.example.com/users/${userId}`
    );
  });

  it("should throw an error when the API returns an error", async () => {
    // Arrange
    mockedAxios.get.mockRejectedValue(new Error("Network Error"));

    // Act and Assert
    await expect(getUser(1)).rejects.toThrow("Network Error");
  });
});
```

### Stubs

- Stubs are objects that return predetermined data and do not have complex logic.

  - How are they used?
    - Used to provide fixed responses to calls during testing, allowing you to control the test environment.
    - Example: A stub can always return the same list of users when calling a getUsers method

- emailService.ts

```ts
// emailService.ts
export interface Email {
  to: string;
  subject: string;
  body: string;
}

export async function sendEmail(email: Email): Promise<void> {
  // Imagine this function actually sends an email
  console.log(`Sending email to ${email.to}`);
}
```

- notificationService.ts

```ts
// notificationService.ts
import { Email, sendEmail } from "./emailService";

export async function notifyUser(
  email: string,
  message: string
): Promise<void> {
  const emailData: Email = {
    to: email,
    subject: "Notification",
    body: message,
  };

  await sendEmail(emailData);
}
```

- notificationService.test.ts

```ts
// notificationService.test.ts
import { notifyUser } from "./notificationService";
import * as emailService from "./emailService";

describe("notifyUser", () => {
  it("should call sendEmail with the correct parameters", async () => {
    // Arrange
    const email = "test@example.com";
    const message = "Hello, this is a notification.";

    // Stub the sendEmail function
    const sendEmailStub = jest
      .spyOn(emailService, "sendEmail")
      .mockResolvedValue();

    // Act
    await notifyUser(email, message);

    // Assert
    expect(sendEmailStub).toHaveBeenCalledWith({
      to: email,
      subject: "Notification",
      body: message,
    });

    // Cleanup
    sendEmailStub.mockRestore();
  });
});
```

### Fakes

- Fakes are simplified implementations that function as lighter versions of the real components.

  - How are they used?
    - Used when the full implementation is complex or not available. Fakes may have internal logic, but are simpler than the real thing.
    - Example: An in-memory database that replaces a real database for testing

- databaseService.ts

```ts
// databaseService.ts
export interface User {
  id: number;
  name: string;
}

export interface Database {
  getUserById(id: number): Promise<User | null>;
  saveUser(user: User): Promise<void>;
}

export class RealDatabase implements Database {
  private users: User[] = [];

  async getUserById(id: number): Promise<User | null> {
    return this.users.find(user => user.id === id) || null;
  }

  async saveUser(user: User): Promise<void> {
    this.users.push(
  }
}
```

- userRepository.ts

```ts
// userRepository.ts
import { Database, User } from "./databaseService";

export class UserRepository {
  constructor(private database: Database) {}

  async getUser(id: number): Promise<User | null> {
    return await this.database.getUserById(id);
  }

  async addUser(user: User): Promise<void> {
    await this.database.saveUser(user);
  }
}
```

- userRepository.test.ts

```ts
// userRepository.test.ts
import { UserRepository } from "./userRepository";
import { Database, User } from "./databaseService";

// Fake implementation of the Database interface
class FakeDatabase implements Database {
  private users: User[] = [];

  async getUserById(id: number): Promise<User | null> {
    return this.users.find(user => user.id === id) || null;
  }

  async saveUser(user: User): Promise<void> {
    this.users.push(user);
  }
}

describe("UserRepository", () => {
  it("should add and retrieve a user", async () => {
    // Arrange
    const fakeDatabase = new FakeDatabase();
    const userRepository = new UserRepository(fakeDatabase);
    const user: User = { id: 1, name: "John Doe" };

    // Act
    await userRepository.addUser(user);
    const retrievedUser = await userRepository.getUser(user.id);

    // Assert
    expect(retrievedUser).toEqual(user);
  });

  it("should return null if user does not exist", async () => {
    // Arrange
    const fakeDatabase = new FakeDatabase();
    const userRepository = new UserRepository(fakeDatabase);

    // Act
    const retrievedUser = await userRepository.getUser(1);

    // Assert
    expect(retrievedUser).toBeNull();
  });
});
```

### Spies

- Is a tool used to monitor and verify the interaction with functions, methods, or objects.
- The spy records information about how and how many times a function was called, with which arguments, and can even override the behavior of the original function to verify that it is being used correctly during testing.

- paymentService.ts

```ts
// paymentService.ts
export interface PaymentDetails {
  amount: number;
  method: string;
}

export class PaymentService {
  async processPayment(paymentDetails: PaymentDetails): Promise<void> {
    // Imagine this function actually processes a payment
    console.log(
      `Processing payment of ${paymentDetails.amount} using ${paymentDetails.method}`
    );
  }
}
```

- checkoutService.ts

```ts
// checkoutService.ts
import { PaymentService, PaymentDetails } from "./paymentService";

export class CheckoutService {
  constructor(private paymentService: PaymentService) {}

  async checkout(paymentDetails: PaymentDetails): Promise<void> {
    await this.paymentService.processPayment(paymentDetails);
  }
}
```

- checkoutService.test.ts

```ts
// checkoutService.test.ts
import { CheckoutService } from "./checkoutService";
import { PaymentService, PaymentDetails } from "./paymentService";

describe("CheckoutService", () => {
  it("should call processPayment with the correct parameters", async () => {
    // Arrange
    const paymentService = new PaymentService();
    const checkoutService = new CheckoutService(paymentService);
    const paymentDetails: PaymentDetails = {
      amount: 100,
      method: "CreditCard",
    };

    // Spy on the processPayment method
    const processPaymentSpy = jest
      .spyOn(paymentService, "processPayment")
      .mockResolvedValue();

    // Act
    await checkoutService.checkout(paymentDetails);

    // Assert
    expect(processPaymentSpy).toHaveBeenCalledWith(paymentDetails);
    expect(processPaymentSpy).toHaveBeenCalledTimes(1);

    // Cleanup
    processPaymentSpy.mockRestore();
  });
});
```

### Use Cases

- Mocks
  - Verify Interactions: Verify that specific methods were called.
  - Example: Test that the save function is called with certain arguments after an operation.
- Stubs
  - Control the Test Environment: Provide fixed data to ensure predictable results.
  - Example: Return a specific response from an API during testing, regardless of what the real API would do.
- Fakes
  - Replace Complex Implementations: Use simpler versions of components to make testing faster and more isolated.
  - Example: Use an in-memory database for testing instead of a real database that can be slow and difficult to configure.
- Spies
  - Capture Interactions: Record how certain components are used during testing.
  - Example: Monitor how many times a particular method is called or what parameters were passed to it during a test.

## Simple Summary

- Mocks: Simulate and verify interactions (if a method was called).
- Stubs: Provide fixed responses (return predefined data).
- Fakes: Replace real components with simplified versions (they work, but are simpler).
- Spies: Used to monitor and verify the interaction with functions, methods, or objects

## Practical Example

- Imagine you are testing an e-commerce application:
  - Mock: Verify that the sendInvoice method is called after an order is finalized.
  - Stub: Always return the same list of products when calling getAvailableProducts.
  - Fake: Use an in-memory database to test adding products to the cart, instead of a real database.
  - Spies: Verify if a sendEmail method was called with the correct arguments and received the correct message when user registers.

<br><br>
