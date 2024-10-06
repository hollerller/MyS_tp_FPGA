library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity NCO_tb is
end;

architecture NCO_tb_arch of NCO_tb is
        -- declarations
    component NCO is
        port (
			clk_i: in std_logic;
			rst_i: in std_logic;
			ena_i: in std_logic;
			pha_i: in std_logic_vector(15 downto 0);
			q_o:   out std_logic_vector(11 downto 0)
        );
    end component NCO;

	signal   clk_tb: std_logic := '0';
	signal   rst_tb: std_logic := '1';
	signal 	 ena_tb: std_logic := '0';	
	signal   pha_tb: std_logic_vector(15 downto 0) := "0011101100001110";
	signal   q_tb:   std_logic_vector(11 downto 0);

begin
        -- behavior

	clk_tb <= not clk_tb after 4 ns;		
	rst_tb <= '0' after 20 ns;
	ena_tb <= '1' after 20 ns, '0' after 100 ns, '1' after 200 ns;
	ena_tb <= '1' after 40 ns;


	DUT: NCO
		port map(
			clk_i => clk_tb,
			rst_i => rst_tb,
			ena_i => ena_tb,
			pha_i => pha_tb,
			q_o   => q_tb
		);            

end architecture;