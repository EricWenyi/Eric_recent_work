package Default;

import java.util.Scanner;

public class Battleship
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int [][] board = new int [5][5];
        int [][] ship = new int [4][2];
        int [] shot = new int[2];
        boolean done = false;

        resetboard(board);
        while(!done) 
        {   
            displayBoard(board);
            displayMenu();
            int xx = (int)(Math.random() * 4);
            int yy = (int)(Math.random() * 4);
            
            

            ship[0][0] = xx;
            ship[0][1] = yy;
            ship[1][0] = xx + 1;
            ship[1][1] = yy;
            ship[2][0] = xx;
            ship[2][1] = yy + 1;
            ship[3][0] = xx + 1;
            ship[3][1] = yy + 1;
            int choice = getMenuInput(input);       
            if(choice == 1)
            {   
                getRow(shot);
                getColumn(shot);
                if(fireShot(shot,ship) == true)
                {
                    board[shot[0]][shot[1]]= 1;

                }
                else
                {
                    board[shot[0]][shot[1]]= 0;

                }
            }
            else if(choice == 2)
            {
                for (int x = 0; x < 5; x++)
                {
                    for(int y = 0; y < 5; y++)
                    {
                        for(int z = 0; z < 3; z++)
                        {
                            if(board[x][y] == ship[z][0] && board[x][y] == ship[z][1] )
                            {
                                board[ship[z][0]][ship[z][1]]= 1;
                            }
                        }
                    }
                }
                displayBoard(board);
            }
            else if (choice == 3)
            {
                done = true;
                System.out.println("Thanks For Playing");

            }
        }

    }
    
    
    public static void displayBoard(int [][] board)
    {
        System.out.println("  A B C D E");
        for(int r =0; r < 5; r++) //row
        { 
            System.out.print((r + 1) + ""); //print out row number
            for(int c = 0; c < 5; c++)
            {
                if(board[r][c] == -1)
                {
                    System.out.print(" -");
                }
                else if(board[r][c] == 0)
                {
                    System.out.print(" X");
                }
                else if(board[r][c] == 1)
                {
                    System.out.print(" *");
                }
            }
            System.out.println("");
        }

    }
    
    public static void resetboard(int[][] a)//reset the whole board
    {
        for(int row=0 ; row < 5 ; row++ )
        {
            for(int column=0 ; column < 5 ; column++ )
            {
                a[row][column]=-1;
            }
        }
    }
    
    public static void displayMenu()
    {
        System.out.println("\nMenu:");
        System.out.println("1. Fire Shot");
        System.out.println("2. Show Solution");
        System.out.println("3. Quit");

    }
    
    public static int getMenuInput(Scanner input)
    {
        int in = 0;
        if(input.hasNextInt())
        {
            in = input.nextInt();
            if(in>0 && in<4)
            {
                in = in;            
            }
            else 
            {
                System.out.println("Invalid Entry, Please Try Again.\n");
            }
        }
        else 
        {
            System.out.println("Invalid Entry, Please Try Again.\n");
            input.nextInt();
        }
        return in;
    }

    public static void getRow(int [] shot)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a Row Number: ");
        shot[0] = shotValid(input);
        shot[0]--;
    }
    
    public static void getColumn(int [] shot)
    {
        Scanner input = new Scanner(System.in);
         int numb = 0;
        System.out.println("Enter a Column Letter: ");
        String choice = input.next();
        if (choice.equals("A"))
        {
            numb = 0;
        }
        else if(choice.equals("B"))
        {
            numb = 1;
        }
        else if( choice.equals("C"))
        {
            numb = 2;
        }
        else if(choice.equals("D"))
        {
            numb = 3;
        }
        else if(choice.equals("E"))
        {
            numb = 4;  
        }
        else
        {
            System.out.println("2Invalid Entry, Please Try Again.\n");
            input.nextLine();
        }
        shot[1] = numb;
    }

    public static boolean fireShot(int [] shot, int [][]ship)
    {
        boolean result = false;
        for(int shipHit=0 ; shipHit<ship.length ; shipHit++)
        {
            if( shot[0]==ship[shipHit][0] && shot[1]==ship[shipHit][1])
            {
                result = true;
            }else
            {
                result = false;
            }
        }
        return result;
    }
    
    public static int shotValid(Scanner quantity)
    {
        int shot = 0;
        boolean done = false;
        while(!done)
        {
            if(quantity.hasNextInt())
            {
                shot = quantity.nextInt();
                if(shot>0 && shot<6)
                {   
                    shot = shot;
                    done = true;
                }
                else 
                {
                    System.out.println("1Invalid Entry, Please Try Again.\n");
                }
            }
            else 
            {
                System.out.println("2Invalid Entry, Please Try Again.\n");
                quantity.next();
            }
        }
        return shot;
    }
}
