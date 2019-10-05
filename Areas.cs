using System;

namespace Areas
{
	class Areas
	{
		public static double Triangle(double b, double h) {
			return (b*h)/2;
		}
		public static double Rectangle(double b, double h) {
			return b*h;
		}
		public static double Square(double s) {
			return s*s;
		}
		public static double Circle(double r) {
			return Math.PI*(r*r);
		}
		public static double Rhombus(double d1, double d2)
		{
			return (d1*d2)/2;
		}
		public static double Rhomboid(double b, double h) {
			return b*h;
		}
		public static double Trapeze(double b1, double b2, double h) {
			return ((b1 + b2) / 2) * h;
		}
		public static double Regular_polygon(double p, double h) {
			return (p*h)/2;
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			double b, h, A;
			Console.Write("Please write the base of your triangle:");
			b = double.Parse(Console.ReadLine());
			Console.Write("Please write the height of your triangle:");
			h = double.Parse(Console.ReadLine());
			A = Areas.Triangle(b, h);
			Console.WriteLine("The area of your triangle is: {0}", A);
		}
	}
}
