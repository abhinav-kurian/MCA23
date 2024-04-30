import java.util.Scanner;
public class matrixmultiplier{
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of the first matrix: ");
        int r1=s.nextInt();
        int c1=s.nextInt();
        System.out.println("Enter the number of rows and columns of the second matrix: ");
        int r2=s.nextInt();
        int c2=s.nextInt();
        if(c1 != r2){
            System.out.println("Matrices cannot be multiplied!");
        }   
        else{
            int matrix1 [][]= inputmatrix(s, r1, c1);
            int matrix2 [][]= inputmatrix(s, r2, c2);
            multiply(matrix1,matrix2);
        }
     
    }
        public static int[][] inputmatrix(Scanner s,int row, int col) {
            int matrix[][]=new int[row][col];
            System.out.println("Enter elements of the matrix:");
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    matrix [i][j]=s.nextInt();
                    }
                }
            System.out.println("The result matrix is");
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    System.out.print(matrix[i][j]+" ");
                    }
                    System.out.println();
                }
                return matrix;
            }
            public static  void  multiply(int[][] matrix1, int[][] matrix2) {
                int rows1= matrix1.length;
                int cols1= matrix1[0].length;
                int cols2= matrix2[0].length;
                int result[][] = new int[rows1][cols2];
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols2; j++) {
                        for (int k = 0; k < cols1; k++) {
                            result[i][j] += matrix1[i][k] * matrix2[k][j];
                        }
                    }
                }
                System.out.println("the result matrix is ");
                for(int i=0;i<rows1;i++)
                {
                    for(int j=0;j<cols2;j++)
                    {
                        System.out.print(result[i][j] +" ");
                    }  
                     System.out.println();
                    
                }
            

            }
        
}
