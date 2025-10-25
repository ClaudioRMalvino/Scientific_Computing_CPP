import matplotlib.pyplot as plt
import numpy as np


def main() -> None:
    euler_file = "euler.dat"
    euler_data = np.loadtxt(euler_file, delimiter=",")
    euler_x = euler_data[:, 0]
    euler_y = euler_data[:, 1]
    runge_kutta_file = "rungeKutta.dat"
    runge_kutta_data = np.loadtxt(runge_kutta_file, delimiter=",")
    runge_kutta_x = runge_kutta_data[:, 0]
    runge_kutta_y = runge_kutta_data[:, 1]

    plt.plot(euler_x, euler_y)
    plt.title("Euler Method")
    plt.xlabel("t")
    plt.ylabel("f(y,t)")

    plt.plot(runge_kutta_x, runge_kutta_y)
    plt.title("Runge Kutta Method")
    plt.xlabel("t")
    plt.ylabel("f(y,t)")
    plt.show()


if __name__ == "__main__":
    main()
