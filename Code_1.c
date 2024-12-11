import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt
class CarbonFootprintAnalyser:
    def __init__(self, master):
        self.master = master
        self.master.title('CARBON FOOTPRINT ANALYSER')

        self.label_electricity = tk.Label(self.master, text='Electricity (kWh):')
        self.label_electricity.grid(row=0, column=0)
        self.entry_electricity = tk.Entry(self.master)
        self.entry_electricity.grid(row=0, column=1)

        self.label_petrol = tk.Label(self.master, text='Petrol (liters):')
        self.label_petrol.grid(row=1, column=0)
        self.entry_petrol = tk.Entry(self.master)
        self.entry_petrol.grid(row=1, column=1)

        self.label_diesel = tk.Label(self.master, text='Diesel (liters):')
        self.label_diesel.grid(row=2, column=0)
        self.entry_diesel = tk.Entry(self.master)
        self.entry_diesel.grid(row=2, column=1)

        self.label_ev = tk.Label(self.master, text='Electric Vehicle (km):')
        self.label_ev.grid(row=3, column=0)
        self.entry_ev = tk.Entry(self.master)
        self.entry_ev.grid(row=3, column=1)

        self.label_tree = tk.Label(self.master, text='Trees planted:')
        self.label_tree.grid(row=4, column=0)
        self.entry_tree = tk.Entry(self.master)
        self.entry_tree.grid(row=4, column=1)

        self.button_calculate = tk.Button(self.master, text='Calculate', command=self.calculate)
        self.button_calculate.grid(row=5, column=0, columnspan=2)

    def calculate(self):
        electricity = int(self.entry_electricity.get())
        petrol = int(self.entry_petrol.get())
        diesel = int(self.entry_diesel.get())
        ev = int(self.entry_ev.get())
        tree = int(self.entry_tree.get())

        elect = electricity * 0.8
        pet = petrol * 2.4
        die = diesel * 2.6
        e = ev * 0.2
        tc = elect + pet + die + e + tree * 2

        messagebox.showinfo('Result', f'The total carbon footprint emitted in a month is {tc} kg of CO2 per month')

        labels = ['Electricity', 'Petrol', 'Diesel', 'Electric Vehicle']
        sizes = [elect, pet, die, e]
        plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
        plt.axis('equal')
        plt.show()

if __name__ == '__main__':
    root = tk.Tk()
    app = CarbonFootprintAnalyser(root)
    root.mainloop()
