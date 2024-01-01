#include <iostream>
#include <string>
#include <algorithm> // Added for swap function

using namespace std;

class Movie
{
public:
	int movieID;
	string title;
	string genre;
	double ratings;
	Movie *left;
	Movie *right;

	Movie(int movieID, string title, string genre, double ratings)
	{
		this->movieID = movieID;
		this->title = title;
		this->genre = genre;
		this->ratings = ratings;
		left = right = nullptr;
	}
};

class MovieRecommendationSystem
{
private:
	Movie *root;

public:
	MovieRecommendationSystem()
	{
		root = nullptr;
	}

	// Insert a movie into the BST
	void insertMovie(Movie *&root, int movieID, string title, string genre, double ratings)
	{
		if (root == nullptr)
		{
			root = new Movie(movieID, title, genre, ratings);
		}
		else if (movieID < root->movieID)
		{
			insertMovie(root->left, movieID, title, genre, ratings);
		}
		else
		{
			insertMovie(root->right, movieID, title, genre, ratings);
		}
	}

	// Recommend movies of a given genre
	void recommendMoviesByGenre(Movie *root, string genre)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->genre == genre)
		{
			cout << root->title << " " << root->ratings << endl;
		}
		recommendMoviesByGenre(root->left, genre);
		recommendMoviesByGenre(root->right, genre);
	}

	// Delete a movie by ID
	Movie *deleteMovieByID(int movieID, Movie *root)
	{
		if (root == nullptr)
		{
			return root;
		}
		if (movieID > root->movieID)
		{
			root->right = deleteMovieByID(movieID, root->right);
		}
		else if (movieID < root->movieID)
		{
			root->left = deleteMovieByID(movieID, root->left);
		}
		else
		{
			if (root->left == nullptr)
			{
				Movie *temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Movie *temp = root->left;
				delete root;
				return temp;
			}

			Movie *minValueNode = findMinValueNode(root->right);
			root->title = minValueNode->title;
			root->movieID = minValueNode->movieID;
			root->genre = minValueNode->genre;
			root->ratings = minValueNode->ratings;
			root->right = deleteMovieByID(minValueNode->movieID, root->right);
		}

		return root;
	}

	Movie *findMinValueNode(Movie *root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->left != nullptr)
		{
			return findMinValueNode(root->left);
		}

		return root;
	}

	// Perform an in-order traversal of the tree and display movies
	void displayMovies(Movie *root)
	{
		if (root == nullptr)
		{
			return;
		}
		displayMovies(root->left);
		cout << root->title << endl;
		displayMovies(root->right);
	}
};

int main()
{
	Movie *root = nullptr;
	MovieRecommendationSystem engine;
	int choice;
	while (true)
	{
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Title\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int movieID;
			string title, genre;
			double ratings;
			cout << "Enter Movie ID: ";
			cin >> movieID;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Movie Title: ";
			getline(cin, title);
			cout << "Enter Movie Genre: ";
			getline(cin, genre);
			cout << "Enter Ratings: ";
			cin >> ratings;

			engine.insertMovie(root, movieID, title, genre, ratings);
			cout << "Movie added successfully!" << endl;
			break;
		}
		case 2:
		{
			int deleteID;
			cout << "Enter Movie ID to delete: ";
			cin >> deleteID;
			root = engine.deleteMovieByID(deleteID, root);
			cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
			break;
		}
		case 3:
		{
			string genre;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter your favorite genre: ";
			getline(cin, genre);
			engine.recommendMoviesByGenre(root, genre);
			break;
		}
		case 4:
			engine.displayMovies(root);
			break;
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}